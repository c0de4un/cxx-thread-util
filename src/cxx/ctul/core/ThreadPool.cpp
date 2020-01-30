/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef CTUL_CORE_THREAD_POOL_HPP
#include "ThreadPool.hpp"
#endif // !CTUL_CORE_THREAD_POOL_HPP

// PLATFORM
#if defined( WIN32 ) || defined( WIN64 )

// Include ctul::windows::WinThread
#ifndef CTUL_WIN_THREAD_HPP
#include "../windows/WinThread.hpp"
#endif // !CTUL_WIN_THREAD_HPP
using ctul_Thread_t = ctul::win::WinThread;
#elif defined( LINUX ) || defined( Linux ) || defined( _linux ) || defined( __linux__ ) || defined( __linux )

// Include ctul::posix::PThread
#ifndef CTUL_POSIX_THREAD_HPP
#include "../posix/PThread.hpp"
#endif // !CTUL_POSIX_THREAD_HPP
using ctul_Thread_t = ctul::posix::PThread;
#endif
// PLATFORM

// Include ctul::core::ThreadGroup
#ifndef CTUL_CORE_THREAD_GROUP_HPP
#include "ThreadGroup.hpp"
#endif // !CTUL_CORE_THREAD_GROUP_HPP

// ===========================================================
// ctul::core::ThreadPool
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // FIELDS
        // ===========================================================

        ThreadPool* ThreadPool::mInstance(nullptr);

        ctul_mutex_t ThreadPool::mPoolMutex;

        // ===========================================================
        // CONSTRUCTORS & DESTRUCTOR
        // ===========================================================

        ThreadPool::ThreadPool()
            : mTGroups(),
            mThreadsMutex()
        {

            // Default thread-group.
            mTGroups[0] = ctul_MakeShared<ctul_ThreadGroup>(0);

        }

        ThreadPool::~ThreadPool()
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        ThreadPool::thread_sptr_t ThreadPool::OnGetThread(const thread_id_t threadID)
        {
            ctul_ulock ulock_(mThreadsMutex);

            tgroups_map_t::iterator pos_ = mTGroups.begin();
            const tgroups_map_t::const_iterator end_ = mTGroups.cend();
            thread_sptr_t thread_(nullptr);

            while (pos_ != end_)
            {
                tgroup_sptr_t& tgroup_ = pos_->second;

                thread_ = tgroup_->GetThread(threadID);

                if (thread_ != nullptr)
                    break;

                pos_++;
            }

            return thread_;
        }

        bool ThreadPool::IsEmpty()
        {
            bool empty_ = true;

            ctul_ulock ulock_(mThreadsMutex);

            tgroups_map_t::iterator pos_ = mTGroups.begin();
            const tgroups_map_t::const_iterator end_ = mTGroups.cend();

            while (pos_ != end_)
            {
                if (!(pos_->second->IsEmpty()))
                {
                    empty_ = false;
                    break;
                }
                pos_++;
            }

            return empty_;
        }

        ThreadPool::thread_sptr_t ThreadPool::GetThread(const thread_id_t threadID)
        { return mInstance ? mInstance->OnGetThread(threadID) : thread_sptr_t(nullptr); }

        // ===========================================================
        // METHODS
        // ===========================================================

        void ThreadPool::OnAdd(thread_sptr_t& pThread)
        { mTGroups[0]->Add(pThread); }

        void ThreadPool::OnRemove(const thread_id_t threadID)
        {
            if (mTGroups.size() > 0)
            {
                tgroups_map_t::iterator pos_ = mTGroups.find(0);

                if (pos_ != mTGroups.end())
                    pos_->second->Remove(threadID);
            }
        }

        void ThreadPool::Add(thread_sptr_t& pThread)
        {
            ctul_ulock ulock_(mPoolMutex);
            
            if (!mInstance)
                mInstance = new ctul_ThreadPool();

            mInstance->OnAdd(pThread);
        }

        void ThreadPool::Remove(const thread_id_t threadID)
        {
            ctul_ulock ulock_(mPoolMutex);

            if (mInstance)
            {
                mInstance->OnRemove(threadID);

                if (mInstance->IsEmpty())
                {
                    delete mInstance;
                    mInstance = nullptr;
                }
            }
        }

        // -----------------------------------------------------------

    }

}

// -----------------------------------------------------------