/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CFG_MEMORY_HPP
#define CTUL_CFG_MEMORY_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include C++ memory
#include <memory> // shared_ptr, make_shared

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// ===========================================================
// TYPES
// ===========================================================

template <typename T>
using sptr_t = std::shared_ptr<T>;

// ===========================================================
// METHODS
// ===========================================================

template <typename T, typename... _Types>
static sptr_t<T> ctul_MakeShared(_Types&& ... _Args)
{ return std::make_shared<T>(std::forward<_Types>(_Args)...); }

// -----------------------------------------------------------

#endif // !CTUL_CFG_MEMORY_HPP