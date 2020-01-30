/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#ifndef CTUL_WIN_THREAD_HPP
#include "WinThread.hpp"
#endif // !CTUL_WIN_THREAD_HPP

// ===========================================================
// ctul::win::WinThread
// ===========================================================

namespace ctul
{

    namespace win
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        WinThread::WinThread(const thread_id_t pID)
            : ThreadBase(pID),
            mThread(nullptr)
        {
        }

        WinThread::~WinThread()
        {
            this->Stop(false);
        }

        // ===========================================================
        // IThread
        // ===========================================================

        bool WinThread::Run()
        {
            const byte_t state_ = GetState();

            if (state_ == ctul_ThreadState::RUNNING)
                return false;
            else if (state_ == ctul_ThreadState::PAUSED)
            {
                mState = ctul_ThreadState::RUNNING;
            }

            if (mThread)
                delete mThread;

            mState = (byte_t)ctul_ThreadState::PAUSED;
            mThread = new ctul_thread_t(ExecuteRun, this);
            return true;
        }

        void WinThread::Pause()
        {
            mState = ctul_ThreadState::PAUSED;
        }

        void WinThread::Stop(const bool pWait)
        {
            if (GetState() == ctul_ThreadState::STOPPED && !mThread)
                return;

            mState = ctul_ThreadState::STOPPED;

            if (mThread)
            {
                if (pWait)
                {
                    if (mThread->joinable())
                        mThread->join();
                    else
                        mThread->detach();
                }

                delete mThread;
                mThread = nullptr;
            }
        }

        // ===========================================================
        // METHODS
        // ===========================================================

        void WinThread::OnRun()
        {
            // Run, while not stopped.
            while (GetState() != ctul_ThreadState::STOPPED)
            {
            }

            // Auto-Stop
            this->Stop(false);
        }

        void WinThread::ExecuteRun(WinThread* const pThread)
        {
            if (pThread)
                pThread->OnRun();
        }

        // -----------------------------------------------------------

    } /// win

} /// ctul

// -----------------------------------------------------------