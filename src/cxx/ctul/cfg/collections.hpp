/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CFG_COLLECTIONS_HPP
#define CTUL_CFG_COLLECTIONS_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include C++ map
#include <map>

// Include C++ vector
#include <vector>

// Include C++ deque
#include <deque>

// ===========================================================
// FORWARD-DECLARATIONS
// ===========================================================

// ===========================================================
// TYPES
// ===========================================================

template <typename K, typename V>
using map_t = std::map<K, V>;

template <typename T>
using vec_t = std::vector<T>;

template <typename T>
using deque_t = std::deque<T>;

// -----------------------------------------------------------

#endif // !CTUL_CFG_COLLECTIONS_HPP