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
#ifndef CTUL_CORE_THREAD_BASE_HPP
#include "ThreadBase.hpp"
#endif // !CTUL_CORE_THREAD_BASE_HPP

// ===========================================================
// ThreadBase
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTOR & DESTRUCTOR
        // ===========================================================

        ThreadBase::ThreadBase(const thread_id_t pID)
            : mID( pID ),
            mState( EThreadState::STOPPED )
        {
        }

        ThreadBase::~ThreadBase()
        {
        }

        // ===========================================================
        // GETTERS & SETTERS
        // ===========================================================

        thread_id_t ThreadBase::GetID() const
        { return mID; }

        byte_t ThreadBase::GetState() const
        {
            const byte_t state_ = mState;
            return state_;
        }

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul

// -----------------------------------------------------------