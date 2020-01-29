/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_I_THREAD_HXX
#define CTUL_CORE_I_THREAD_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::types
#ifndef CTUL_CFG_TYPES_HPP
#include "../cfg/types.hpp"
#endif // !CTUL_CFG_TYPES_HPP

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
         * EThreadState - thread sates enum.
        **/
        enum EThreadState : byte_t
        {

            // -----------------------------------------------------------

            STOPPED,
            RUNNING,
            PAUSED

            // -----------------------------------------------------------

        };

        // -----------------------------------------------------------

        /**
         * @brief
         * IThread - interface to thread-class.
         *
         * @version 0.1
         * @author Denis Z. (code4un@yandex.ru)
        **/
        class IThread
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * IThread destructor.
             *
             * @throws - can throw exception.
            **/
            virtual ~IThread()
            {
            }

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * Returns Thread-ID.
             * 
             * @thread_safety - thread-safe (constant).
             * @returns - Thread-ID.
             * @throws - can throw exception.
            **/
            virtual thread_id_t GetID() const = 0;

            /**
             * @brief
             * Returns current thread state.
             * 
             * @thread_safety - not thread-safe.
             * @returns - thread-state.
             * @throws - can throw exception.
            **/
            virtual byte_t GetState() const = 0;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Start (or resume/restart) thread.
             *
             * @thread_safety - locks used.
             * @returns - 'true' if running (working), 'false' if failed.
             * @throws - can throw exceptions.
            **/
            virtual bool Run() = 0;

            /**
             * @brief
             * Pause this thread.
             * 
             * @thread_safety - atomic-flag used.
             * @throws - can throw exception.
            **/
            virtual void Pause() = 0;

            /**
             * @brief
             * Stop this thread.
             * Stop means that all operations cancelled and there is no resuming available.
             * 
             * @thread_safety - atomic-flag used. Can cause calling-thread to freeze,
             * if wait-flag if 'true'.
             * @throws - can throw exception.
            **/
            virtual void Stop(const bool pWait) = 0;

            // -----------------------------------------------------------

        }; /// ctul::core::IThread

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_IThread = ctul::core::IThread;
#define CTUL_CORE_I_THREAD_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_I_THREAD_HXX