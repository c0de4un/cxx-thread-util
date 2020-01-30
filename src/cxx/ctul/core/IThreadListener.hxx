/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_I_THREAD_LISTENER_HXX
#define CTUL_CORE_I_THREAD_LISTENER_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::memory
#ifndef CTUL_CFG_MEMORY_HPP
#include "../cfg/memory.hpp"
#endif // !CTUL_CFG_MEMORY_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declare ctul::core::IThread
#ifndef CTUL_CORE_I_THREAD_HXX
#define CTUL_CORE_I_THREAD_HXX
namespace ctul
{

    namespace core
    {

        class IThread;

    }

}
using ctul_IThread = ctul::core::IThread;
#endif // !CTUL_CORE_I_THREAD_HXX

// Forward-Declare ctul::core::IThreadEvent
#ifndef CTUL_CORE_I_THREAD_EVENT_DECL
#define CTUL_CORE_I_THREAD_EVENT_DECL
namespace ctul
{

    namespace core
    {

        class IThreadEvent;

    }

}
using ctul_IThreadEvent = ctul::core::IThreadEvent;
#endif // !CTUL_CORE_I_THREAD_EVENT_DECL

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
         * IThreadListener - interface to handle direct-events (messages) from IThread.
         * 
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class IThreadListener
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * IThreadListener destructor.
             * 
             * @thorws - no exceptions.
            **/
            virtual ~IThreadListener()
            {
            }

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Called when event from IThread sent.
             * 
             * @thread_safety - async-operation. IThread can be already deleted (null).
             * @param pEvent - event data.
             * @throws - can throw exception (causing undefined behavior).
            **/
            virtual void HandleThreadEvent(sptr_t<ctul_IThreadEvent> pEvent) = 0;

            // -----------------------------------------------------------

        };

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_IThreadListener = ctul::core::IThreadListener;
#define CTUL_CORE_I_THREAD_LISTENER_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_I_THREAD_LISTENER_HXX