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
#ifndef CTUL_CORE_SMUTEX_HPP
#include "SMutex.hpp"
#endif // !CTUL_CORE_SMUTEX_HPP

// ===========================================================
// ctul::core::SLock
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        // ===========================================================
        // CONSTRUCTORS & DESTRUCTOR
        // ===========================================================

        SMutex::SMutex()
            : mLocked(false),
            mMutex()

        {
        }

        SMutex::~SMutex()
        {
            this->unlock();
        }

        // ===========================================================
        // IMutex
        // ===========================================================

        void SMutex::lock()
        {
            if (!mLocked)
            {
                mMutex.lock();
                mLocked = true;
            }
        }

        bool SMutex::try_lock()
        {
            if (!mLocked)
            {
                return mLocked = mMutex.try_lock();
            }

            return false;
        }

        void SMutex::unlock()
        {
            if (mLocked)
            {
                mMutex.unlock();
            }
        }

        SMutex::nhandle_t SMutex::native_handle()
        {
            return mMutex.native_handle();
        }

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul

// -----------------------------------------------------------