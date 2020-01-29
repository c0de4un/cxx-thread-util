/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_THREAD_ERROR_EVENT_HPP
#define CTUL_CORE_THREAD_ERROR_EVENT_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::core::IThreadEvent
#ifndef CTUL_CORE_I_THREAD_EVENT_HXX
#include "IThreadEvent.hxx"
#endif // !CTUL_CORE_I_THREAD_EVENT_HXX

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

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
         * IThreadEvent - interface for thread event.
         *
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class ThreadErrorEvent final : public ctul_IThreadEvent
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            /** Thread-ID. **/
            const thread_id_t mThreadID;

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ThreadErrorEvent constructor.
             * 
             * @param threadID - Thread-ID.
             * @throws - can throw exception:
             *  - out-of-memory;
            **/
            explicit ThreadErrorEvent(const thread_id_t threadID);

            /**
             * @brief
             * ThreadErrorEvent destructor.
             *
             * @throws - can throw exception.
            **/
            virtual ~ThreadErrorEvent();

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * @brief
             * Returns thread event type.
             *
             * @thread_safety - not required.
             * @returns - EThreadEventType.
             * @throws - no exceptions.
            **/
            virtual byte_t GetType() const final;

            /**
             * @brief
             * Returns Thread-ID.
             *
             * @thread_safety - not required.
             * @returns - thread id.
             * @throws - no exceptions.
            **/
            virtual thread_id_t GetThreadID() const final;

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// ctul::core::ThreadErrorEvent

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul

// -----------------------------------------------------------

#endif // !CTUL_CORE_THREAD_ERROR_EVENT_HPP