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
#ifndef CTUL_CORE_THREAD_ERROR_EVENT_HPP
#include "ThreadErrorEvent.hpp"
#endif // !CTUL_CORE_THREAD_ERROR_EVENT_HPP

// ===========================================================
// ThreadErrorEvent
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        ThreadErrorEvent::ThreadErrorEvent(const thread_id_t threadID)
            : mThreadID(threadID)
        {
        }

        ThreadErrorEvent::~ThreadErrorEvent()
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        byte_t ThreadErrorEvent::GetType() const
        { return (byte_t)EThreadEventType::ERROR; }

        thread_id_t ThreadErrorEvent::GetThreadID() const
        { return mThreadID; }

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul

// -----------------------------------------------------------