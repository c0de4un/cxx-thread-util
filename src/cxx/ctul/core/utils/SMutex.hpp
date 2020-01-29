/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_SMUTEX_HPP
#define CTUL_CORE_SMUTEX_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::core::IMutex
#ifndef CTUL_CORE_I_MUTEX_HXX
#include "IMutex.hxx"
#endif // !CTUL_CORE_I_MUTEX_HXX

// Include ctul::atomic
#ifndef CTUL_CFG_ATOMIC_HPP
#include "../../cfg/atomic.hpp"
#endif // !CTUL_CFG_ATOMIC_HPP

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
         * SMutex - decorator class for C++ mutex.
         * 
         * Allows to avoid dangerous bahavior, when deletion of unlocking may
         * cause undefined behavior (destructor, unlocking none-locked).
         *
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class SMutex final : public ctul_IMutex
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Locked-status. **/
            ctul_atomic<bool> mLocked;

            /** C++ mutex. **/
            std::mutex mMutex;

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTORS & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * SMutex constructor.
             * 
             * @throws - can throw exception (out-of-memory).
            **/
            explicit SMutex();

            /**
             * @brief
             * SMutex destructor.
             * 
             * @throws - can throw exception:
             *  - thread;
             *  - mutex;
             *  - access-violation;
            **/
            virtual ~SMutex();

            // ===========================================================
            // IMutex
            // ===========================================================

            /**
             * @brief
             * Lock this mutex.
             *
             * @thread_safety - atomic-flag used.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual void lock() final;

            /**
             * @brief
             * Try lock this mutex.
             *
             * @thread_safety - atomic-flag used.
             * @returns - 'true' if locked, 'false' if failed.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual bool try_lock() final;

            /**
             * @brief
             * Unlock this mutex.
             *
             * @thread_safety - atomic-flag used.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual void unlock() final;

            /**
             * @brief
             * Returns native-handle with info about mutex.
             *
             * @thread_safety - atomic-flag used.
             * @returns - native-handle for mutex. Depends on platform implementation.
             * @throws - can throw exception, depending of implementation.
            **/
            virtual nhandle_t native_handle() final;

            // -----------------------------------------------------------

        }; /// ctul::core::SLock

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_SMutex = ctul::core::SMutex;
#define CTUL_CORE_SMUTEX_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_SMUTEX_HPP