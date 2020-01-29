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
#ifndef CTUL_POSIX_THREAD_HPP
#include "PThread.hpp"
#endif // !CTUL_POSIX_THREAD_HPP

// ===========================================================
// ctul::posix::PThread
// ===========================================================

namespace ctul
{

    namespace posix
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        PThread::PThread(const thread_id_t pID)
            : ThreadBase(pID)
        {
        }

        PThread::~PThread()
        {
            this->Stop(false);
        }

        // ===========================================================
        // IThread
        // ===========================================================

        bool PThread::Run()
        {
            return false;
        }

        void PThread::Pause()
        {

        }

        void PThread::Stop(const bool pWait)
        {

        }

        // -----------------------------------------------------------

    } /// posix

} /// ctul

// -----------------------------------------------------------