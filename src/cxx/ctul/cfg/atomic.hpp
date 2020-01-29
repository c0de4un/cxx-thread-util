/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CFG_ATOMIC_HPP
#define CTUL_CFG_ATOMIC_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include C++ atomic
#include <atomic>

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================


// ===========================================================
// TYPES
// ===========================================================

using ctul_aflag = std::atomic_flag;

template <typename T>
using ctul_atomic = std::atomic<T>;

// -----------------------------------------------------------

#endif // !CTUL_CFG_ATOMIC_HPP