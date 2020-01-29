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
#ifndef CTUL_CORE_THREAD_GROUP_HPP
#include "ThreadGroup.hpp"
#endif // !CTUL_CORE_THREAD_GROUP_HPP

// Include ctul::core::IThread
#ifndef CTUL_CORE_I_THREAD_HXX
#include "IThread.hxx"
#endif // !CTUL_CORE_I_THREAD_HXX

// ===========================================================
// ctul::core::ThreadGroup
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        ThreadGroup::ThreadGroup(const thread_group_id_t pID)
            : mThreadsMutex(),
            mThreads(),
            mID( pID )
        {
        }

        ThreadGroup::~ThreadGroup()
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        thread_group_id_t ThreadGroup::GetID() const
        { return mID; }

        ThreadGroup::thread_ptr_t ThreadGroup::GetThread(const thread_id_t threadID)
        {
            ctul_ulock ulock_(mThreadsMutex);

            for (thread_ptr_t& thread_ : mThreads)
            {
                if (thread_->GetID() == threadID)
                    return thread_;
            }

            return thread_ptr_t(nullptr);
        }

        // ===========================================================
        // IThreadGroup
        // ===========================================================

        void ThreadGroup::Add(thread_ptr_t& pThread)
        {
            ctul_ulock ulock_(mThreadsMutex);
            mThreads.push_back(pThread);
        }

        void ThreadGroup::Remove(thread_ptr_t& pTHread)
        {
            ctul_ulock ulock_(mThreadsMutex);
            
            if (mThreads.size() > 2)
            {
                threads_list_t::iterator pos_ = std::find(mThreads.begin(), mThreads.end(), pTHread);

                if (pos_ != mThreads.end())
                {
                    std::iter_swap(pos_, mThreads.end());
                    mThreads.pop_back();
                }
            }
            else
                mThreads.erase(std::find(mThreads.begin(), mThreads.end(), pTHread));
        }

        ThreadGroup::thread_ptr_t ThreadGroup::Remove(const thread_id_t threadID)
        {
            ctul_ulock ulock_(mThreadsMutex);
            const std::size_t threadsNum = mThreads.size();
            threads_list_t::iterator pos_ = mThreads.begin();
            const threads_list_t::const_iterator end_ = mThreads.cend();

            while (pos_ != end_)
            {
                thread_ptr_t& thread_ = *pos_;

                if (thread_->GetID() == threadID)
                {
                    thread_ptr_t result_ = thread_;
                    if (threadsNum > 2)
                    {
                        std::iter_swap(pos_, mThreads.end());
                        mThreads.pop_back();
                    }
                    else
                        mThreads.erase(pos_);
                    return result_;
                }

                pos_++;
            }

            return thread_ptr_t(nullptr);
        }

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul

// -----------------------------------------------------------