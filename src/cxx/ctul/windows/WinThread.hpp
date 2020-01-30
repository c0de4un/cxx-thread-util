/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_WIN_THREAD_HPP
#define CTUL_WIN_THREAD_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::core::ThreadBase
#ifndef CTUL_CORE_THREAD_BASE_HPP
#include "../core/ThreadBase.hpp"
#endif // !CTUL_CORE_THREAD_BASE_HPP

// Include ctul::thread
#ifndef CTUL_CFG_THREAD_HPP
#include "../cfg/thread.hpp"
#endif // !CTUL_CFG_THREAD_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace ctul
{

    namespace win
    {

        // -----------------------------------------------------------

        /**
         * WinThread - decorator-class for POSIX-based thread-api.
         *
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class WinThread : public ctul_ThreadBase
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** POSIX Thread. **/
            ctul_thread_t* mThread;

            // ===========================================================
            // DELETED
            // ===========================================================

            WinThread(const WinThread&) = delete;
            WinThread& operator=(const WinThread&) = delete;
            WinThread(WinThread&&) = delete;
            WinThread& operator=(WinThread&&) = delete;

            // -----------------------------------------------------------

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Runs thread logic.
             *
             * @thread_safety - only current thread have access.
             * @throws - can throw exception.
            **/
            virtual void OnRun();

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTRUCTOR & DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * WinThread constructor.
             *
             * @param pID - thread id.
             * @throws - can throw exception:
             *  - out-of-memory;
            **/
            explicit WinThread(const thread_id_t pID);

            /**
             * @brief
             * WinThread destructor.
             *
             * @throws - can throw exception:
             *  - access-violation;
             *  - mutex;
            **/
            virtual ~WinThread();

            // ===========================================================
            // IThread
            // ===========================================================

            /**
             * @brief
             * Start (or resume/restart) thread.
             *
             * @thread_safety - locks used.
             * @returns - 'true' if running (working), 'false' if failed.
             * @throws - can throw exceptions.
            **/
            virtual bool Run() final;

            /**
             * @brief
             * Pause this thread.
             *
             * @thread_safety - atomic-flag used.
             * @throws - can throw exception.
            **/
            virtual void Pause() final;

            /**
             * @brief
             * Stop this thread.
             * Stop means that all operations cancelled and there is no resuming available.
             *
             * @thread_safety - atomic-flag used. Can cause calling-thread to freeze,
             * if wait-flag if 'true'.
             * @throws - can throw exception.
            **/
            virtual void Stop(const bool pWait) final;

            // ===========================================================
            // METHODS
            // ===========================================================

            /**
             * @brief
             * Static method used to run thread logic.
             *
             * @thread_safety - unique call for each thread.
             * @param pThread - thread to run.
             * @throws - can throw exception:
             *  - mutex;
             *  - access-violation.
             * All exceptions (errors) reported using IThreadEvent (Events/Messages).
            **/
            static void ExecuteRun(WinThread* const pThread);

            // -----------------------------------------------------------

        }; /// ctul::win::WinThread

        // -----------------------------------------------------------

    } /// win

} /// ctul

using ctul_WinThread = ctul::win::WinThread;
#define CTUL_WIN_THREAD_DECL

// -----------------------------------------------------------

#endif // !CTUL_WIN_THREAD_HPP