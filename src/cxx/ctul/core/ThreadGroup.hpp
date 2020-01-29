/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_THREAD_GROUP_HPP
#define CTUL_CORE_THREAD_GROUP_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::core::IThreadGroup
#ifndef CTUL_CORE_I_THREAD_GROUP_HXX
#include "IThreadGroup.hxx"
#endif // !CTUL_CORE_I_THREAD_GROUP_HXX

// Include ctul::collections
#ifndef CTUL_CFG_COLLECTIONS_HPP
#include "../cfg/collections.hpp"
#endif // !CTUL_CFG_COLLECTIONS_HPP

// Include ctul::memory
#ifndef CTUL_CFG_MEMORY_HPP
#include "../cfg/memory.hpp"
#endif // !CTUL_CFG_MEMORY_HPP

// Include ctul::mutex
#ifndef CTUL_CFG_MUTEX_HPP
#include "../cfg/mutex.hpp"
#endif // !CTUL_CFG_MUTEX_HPP

// Include ctul::core::SMutex
#ifndef CTUL_CORE_SMUTEX_HPP
#include "utils/SMutex.hpp"
#endif // !CTUL_CORE_SMUTEX_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        /**
         * @brief
         * ThreadGroup - handles group of IThreads.
         *
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class ThreadGroup final : public ctul_IThreadGroup
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Threads collection access mutex. **/
            ctul_mutex_t mThreadsMutex;

            /** Threads. **/
            threads_list_t mThreads;

            // ===========================================================
            // DELETED
            // ===========================================================

            ThreadGroup(const ThreadGroup&) = delete;
            ThreadGroup& operator=(const ThreadGroup&) = delete;
            ThreadGroup(ThreadGroup&&) = delete;
            ThreadGroup& operator=(ThreadGroup&&) = delete;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            /** Thread-Group ID. **/
            const thread_group_id_t mID;

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ThreadGroup constructor.
             * 
             * @param pID - Thread-Group ID.
             * @throws - can throw out-of-memory exception.
            **/
            explicit ThreadGroup(const thread_group_id_t pID);

            /**
             * @brief
             * ThreadGroup destructor.
             * 
             * @throws - can throw exception (access-violation, mutex).
            **/
            virtual ~ThreadGroup();

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns Thread-Group-ID.
             *
             * @thread_safety - const. value returned.
             * @throws - no exceptions.
            **/
            virtual thread_group_id_t GetID() const final;

            /**
             * @brief
             * Searches for the IThread using ID.
             *
             * @thread_safety - locks used.
             * @param threadID - IThread ID.
             * @returns IThread, or null.
             * @throws - can throw exception:
             *  - mutex;
             *  - access-violation;
             *  - out-of-memory;
            **/
            virtual thread_ptr_t GetThread(const thread_id_t threadID) final;

            // ===========================================================
            // IThreadGroup
            // ===========================================================

            /**
             * @brief
             * Adds (push) IThread to this group.
             *
             * @thread_safety - locks used.
             * @param pThread - IThread to add.
             * @throws - can throw exception:
             *  - out-of-memory;
             *  - mutex;
             *  - access-violation;
            **/
            virtual void Add(thread_ptr_t& pThread) final;

            /**
             * @brief
             * Removes (pop) IThread from this group.
             *
             * @thread_safety - locks used.
             * @param pThread - IThread to remove.
             * @throws - can throw exception:
             *  - out-of-memory;
             *  - mutex;
             *  - access-violation;
            **/
            virtual void Remove(thread_ptr_t& pTHread) final;

            /**
             * @brief
             * Removes (pop) IThread from this group, using it's ID.
             *
             * @thread_safety - locks used.
             * @param threadID - IThread ID.
             * @returns - IThread, or null.
             * @throws - can throw exception:
             *  - out-of-memory;
             *  - mutex;
             *  - access-violation;
            **/
            virtual thread_ptr_t Remove(const thread_id_t threadID) final;

            // -----------------------------------------------------------

        }; /// ctul::core::ThreadGroup

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_ThreadGroup = ctul::core::ThreadGroup;
#define CTUL_CORE_THREAD_GROUP_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_THREAD_GROUP_HPP