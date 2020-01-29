/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_I_MUTEX_HXX
#define CTUL_CORE_I_MUTEX_HXX

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::mutex (recursive)
#ifndef CTUL_CFG_MUTEX_HPP
#include "../../cfg/mutex.hpp"
#endif // !CTUL_CFG_MUTEX_HPP

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
         * IMutex - interface to describe basic mutex behavior.
         * 
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class IMutex
        {

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONFIGS
            // ===========================================================

            using nhandle_t = std::mutex::native_handle_type;

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * IMutex destructor.
             * 
             * @throws - can throw exception:
             *  - mutex;
             *  - access-violation;
            **/
            virtual ~IMutex()
            {
            }

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================
            
            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Lock this mutex.
             *
             * @thread_safety - atomic-flag used.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual void lock() = 0;

            /**
             * @brief
             * Try lock this mutex.
             * 
             * @thread_safety - atomic-flag used.
             * @returns - 'true' if locked, 'false' if failed.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual bool try_lock() = 0;

            /**
             * @brief
             * Unlock this mutex.
             * 
             * @thread_safety - atomic-flag used.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual void unlock() = 0;

            /**
             * @brief
             * Returns native-handle with info about mutex.
             *
             * @thread_safety - atomic-flag used.
             * @returns - native-handle for mutex. Depends on platform implementation.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual nhandle_t native_handle() = 0;

            // -----------------------------------------------------------

        }; /// ctul::core::IMutex

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_IMutex = ctul::core::IMutex;
#define CTUL_CORE_I_MUTEX_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_I_MUTEX_HXX