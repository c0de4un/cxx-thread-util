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

            

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Threads. **/
            map_t<thread_id_t, vec_t<sptr_t<IThread>>> mThreads;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            // ===========================================================
            // DELETED
            // ===========================================================

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// ctul::core::ThreadPool

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_ThreadPool = ctul::core::ThreadPool;
#define CTUL_CORE_THREAD_POOL_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_THREAD_POOL_HPP