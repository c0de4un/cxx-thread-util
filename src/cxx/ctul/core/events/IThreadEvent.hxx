/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_I_THREAD_EVENT_HXX
#define CTUL_CORE_I_THREAD_EVENT_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::types
#ifndef CTUL_CFG_TYPES_HPP
#include "../../cfg/types.hpp"
#endif // !CTUL_CFG_TYPES_HPP

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
         * EThreadEventType - thread-events enu.
        **/
        enum EThreadEventType : byte_t
        {

            // -----------------------------------------------------------

            ERROR

            // -----------------------------------------------------------

        }; /// ctul::core::EThreadEventType

        // -----------------------------------------------------------

        /**
         * @brief
         * IThreadEvent - interface for thread event.
         * 
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class IThreadEvent
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * IThreadEvent destructor.
             * 
             * @throws - can throw exception.
            **/
            virtual ~IThreadEvent()
            {
            }

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
            virtual byte_t GetType() const = 0;

            /**
             * @brief
             * Returns Thread-ID.
             * 
             * @thread_safety - not required.
             * @returns - thread id.
             * @throws - no exceptions.
            **/
            virtual thread_id_t GetThreadID() const = 0;

            // ===========================================================
            // METHODS
            // ===========================================================

            // -----------------------------------------------------------

        }; /// ctul::core::IThreadEvent

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_EThreadEventType = ctul::core::EThreadEventType;
using ctul_IThreadEvent = ctul::core::IThreadEvent;
#define CTUL_CORE_I_THREAD_EVENT_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_I_THREAD_EVENT_HXX