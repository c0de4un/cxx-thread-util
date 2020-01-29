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

// ===========================================================
// TYPES
// ===========================================================

namespace ctul
{

    namespace win
    {

        // -----------------------------------------------------------

        /**
         * WinThread - decorator-class for Windows-based thread-api.
         *
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class WinThread final : public ctul_ThreadBase
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // FIELDS
            // ===========================================================

            // ===========================================================
            // DELETED
            // ===========================================================

            WinThread(const WinThread&) = delete;
            WinThread& operator=(const WinThread&) = delete;
            WinThread(WinThread&&) = delete;
            WinThread& operator=(WinThread&&) = delete;

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

            // -----------------------------------------------------------

        }; /// ctul::posix::WinThread

        // -----------------------------------------------------------

    } /// win

} /// ctul

using ctul_WinThread = ctul::win::WinThread;
#define CTUL_WIN_THREAD_DECL

// -----------------------------------------------------------

#endif // !CTUL_WIN_THREAD_HPP