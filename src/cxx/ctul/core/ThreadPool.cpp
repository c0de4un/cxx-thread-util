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
#ifndef CTUL_CORE_THREAD_POOL_HPP
#include "ThreadPool.hpp"
#endif // !CTUL_CORE_THREAD_POOL_HPP

// PLATFORM
//#if defined( WIN32 ) || defined( WIN64 )

// Include ctul::windows::WinThread
//#ifndef CTUL_WIN_THREAD_HPP
//#include "../windows/WinThread.hpp"
//#endif // !CTUL_WIN_THREAD_HPP
//using ctul_Thread_t = ctul::win::WinThread;
//#elif defined( LINUX ) || defined( Linux ) || defined( _linux ) || defined( __linux__ ) || defined( __linux )

// Include ctul::posix::PThread
#ifndef CTUL_POSIX_THREAD_HPP
#include "../posix/PThread.hpp"
#endif // !CTUL_POSIX_THREAD_HPP
using ctul_Thread_t = ctul::posix::PThread;
//#endif
// PLATFORM

// ===========================================================
// ctul::core::ThreadPool
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        // -----------------------------------------------------------

    }

}

// -----------------------------------------------------------