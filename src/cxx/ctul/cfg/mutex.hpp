/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CFG_MUTEX_HPP
#define CTUL_CFG_MUTEX_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include C++ mutex
#include <mutex>

// Include ctul::core::SMutex
#ifndef CTUL_CORE_SMUTEX_HPP
#include "../core/utils/SMutex.hpp"
#endif // !CTUL_CORE_SMUTEX_HPP

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// Forward-Declaration of ctul::core::SMutex (required by compiler to prevent type-error).
#ifndef CTUL_CORE_SMUTEX_DECL
#define CTUL_CORE_SMUTEX_DECL
namespace ctul
{

    namespace core
    {

        class SMutex;

    }

}
#endif // !CTUL_CORE_SMUTEX_DECL

// ===========================================================
// TYPES
// ===========================================================

using ctul_mutex_t = ctul::core::SMutex;// std::mutex;
using ctul_ulock = std::unique_lock<ctul_mutex_t>;

// -----------------------------------------------------------

#endif // !CTUL_CFG_MUTEX_HPP