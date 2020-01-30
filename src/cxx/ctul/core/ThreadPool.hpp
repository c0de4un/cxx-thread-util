/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_THREAD_POOL_HPP
#define CTUL_CORE_THREAD_POOL_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::collections
#ifndef CTUL_CFG_COLLECTIONS_HPP
#include "../cfg/collections.hpp"
#endif // !CTUL_CFG_COLLECTIONS_HPP

// Include ctul::types
#ifndef CTUL_CFG_TYPES_HPP
#include "../cfg/types.hpp"
#endif // !CTUL_CFG_TYPES_HPP

// Include ctul::memory
#ifndef CTUL_CFG_MEMORY_HPP
#include "../cfg/memory.hpp"
#endif // !CTUL_CFG_MEMORY_HPP

// Include ctul::mutex
#ifndef CTUL_CFG_MUTEX_HPP
#include "../cfg/mutex.hpp"
#endif // !CTUL_CFG_MUTEX_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declare ctul::core::IThread
#ifndef CTUL_CORE_I_THREAD_DECL
#define CTUL_CORE_I_THREAD_DECL
namespace ctul
{

    namespace core
    {

        class IThread;

    }

}
using ctul_IThread = ctul::core::IThread;
#endif // !CTUL_CORE_I_THREAD_DECL

// Forward-Declare ctul::core::IThreadGroup
#ifndef CTUL_CORE_I_THREAD_GROUP_DECL
#define CTUL_CORE_I_THREAD_GROUP_DECL
namespace ctul
{

    namespace core
    {

        class IThreadGroup;

    }

}
using ctul_IThreadGroup = ctul::core::IThreadGroup;
#endif // !CTUL_CORE_I_THREAD_GROUP_DECL

// ===========================================================
// TYPES
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        /**
         * ThreadPool - helps managing threads and grouping them (factory).
         *
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class ThreadPool final
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // CONFIGS
            // ===========================================================

            using tgroup_t = ctul_IThreadGroup;
            using tgroup_sptr_t = sptr_t<tgroup_t>;
            using thread_sptr_t = sptr_t<ctul_IThread>;
            using tgroups_map_t = map_t<thread_id_t, tgroup_sptr_t>;

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** ThreadPool instance. **/
            static ThreadPool* mInstance;

            /** ThreadPool mutex. **/
            static ctul_mutex_t mPoolMutex;

            /** Thread groups. **/
            tgroups_map_t mTGroups;

            /** Threads map mutex. **/
            ctul_mutex_t mThreadsMutex;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ThreadPool constructor.
             * 
             * @throws - can throw out-of-memory.
            **/
            explicit ThreadPool();

            // ===========================================================
            // DELETED
            // ===========================================================

            ThreadPool(const ThreadPool&) = delete;
            ThreadPool& operator=(const ThreadPool&) = delete;
            ThreadPool(ThreadPool&&) = delete;
            ThreadPool& operator=(ThreadPool&&) = delete;

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Searches for the IThread by id.
             *
             * @thread_safety - lock used.
             * @param threadID - thread id.
             * @returns - IThread, or null.
             * @throws - can throw exception.
            **/
            thread_sptr_t OnGetThread(const thread_id_t threadID);

            /**
             * @brief
             * Check if pool is empty.
             * 
             * @thread_safety - not thread-safe.
             * @throws - no exceptions.
            **/
            bool IsEmpty();

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Add new IThread.
             *
             * @thread_safety - lock used.
             * @param pThread - IThread.
             * @returns - IThread, or null if failed.
             * @throws - can throw exception.
            **/
            void OnAdd(thread_sptr_t& pThread);

            /**
             * @brief
             * Removes thread.
             *
             * @thread_safety - lock used.
             * @param threadID - thread id.
             * @throws - can throw exception.
            **/
            void OnRemove(const thread_id_t threadID);

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ThreadPool destructor.
             * 
             * @throws - can throw exception.
            **/
            ~ThreadPool();

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Searches for the IThread by id.
             * 
             * @thread_safety - lock used.
             * @param threadID - thread id.
             * @returns - IThread, or null.
             * @throws - can throw exception.
            **/
            static thread_sptr_t GetThread(const thread_id_t threadID);

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Add new IThread.
             * 
             * @thread_safety - lock used.
             * @param pThread - IThread.
             * @throws - can throw exception.
            **/
            static void Add(thread_sptr_t& pThread);

            /**
             * @brief
             * Removes thread.
             *
             * @thread_safety - lock used.
             * @param threadID - thread id.
             * @throws - can throw exception.
            **/
            static void Remove(const thread_id_t threadID);

            // -----------------------------------------------------------

        }; /// ctul::core::ThreadPool

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_ThreadPool = ctul::core::ThreadPool;
#define CTUL_CORE_THREAD_POOL_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_THREAD_POOL_HPP