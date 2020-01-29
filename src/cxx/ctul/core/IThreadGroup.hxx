/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_I_THREAD_GROUP_HXX
#define CTUL_CORE_I_THREAD_GROUP_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::types
#ifndef CTUL_CFG_TYPES_HPP
#include "../cfg/types.hpp"
#endif // !CTUL_CFG_TYPES_HPP

// Include ctul::memory
#ifndef CTUL_CFG_MEMORY_HPP
#include "../cfg/memory.hpp"
#endif // !CTUL_CFG_MEMORY_HPP

// Include ctul::collections
#ifndef CTUL_CFG_COLLECTIONS_HPP
#include "../cfg/collections.hpp"
#endif // !CTUL_CFG_COLLECTIONS_HPP

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
         * IThreadGroup - interface to IThreads group.
         *
         * @version 0.1
         * @author Denis Z. (code4un@yandex.ru)
        **/
        class IThreadGroup
        {

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // CONFIGS
            // ===========================================================

            using thread_ptr_t = sptr_t<IThread>;
            using threads_list_t = vec_t<thread_ptr_t>;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * IThreadGroup destructor.
             *
             * @throws - can throw exception.
            **/
            virtual ~IThreadGroup()
            {
            }

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
            virtual thread_group_id_t GetID() const = 0;

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
            virtual thread_ptr_t GetThread(const thread_id_t threadID) = 0;

            // ===========================================================
            // METHODS
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
            virtual void Add(thread_ptr_t& pThread) = 0;

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
            virtual void Remove(thread_ptr_t& pTHread) = 0;

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
            virtual thread_ptr_t Remove(const thread_id_t threadID) = 0;

            // -----------------------------------------------------------

        }; /// ctul::core::IThreadGroup

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_IThreadGroup = ctul::core::IThreadGroup;
#define CTUL_CORE_I_THREAD_GROUP_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_I_THREAD_GROUP_HXX