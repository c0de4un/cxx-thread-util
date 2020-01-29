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
// ctul::posix::WinThread
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
            : ThreadBase(pID)
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
            return false;
        }

        void WinThread::Pause()
        {

        }

        void WinThread::Stop(const bool pWait)
        {

        }

        // -----------------------------------------------------------

    } /// win

} /// ctul

// -----------------------------------------------------------