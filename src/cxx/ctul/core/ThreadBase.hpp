/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef CTUL_CORE_THREAD_BASE_HPP
#define CTUL_CORE_THREAD_BASE_HPP

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// Include ctul::core::IThread
#ifndef CTUL_CORE_I_THREAD_HXX
#include "IThread.hxx"
#endif // !CTUL_CORE_I_THREAD_HXX

// Include ctul::atomic
#ifndef CTUL_CFG_ATOMIC_HPP
#include "../cfg/atomic.hpp"
#endif // !CTUL_CFG_ATOMIC_HPP

// ===========================================================
// TYPES
// ===========================================================

namespace ctul
{

    namespace core
    {

        // -----------------------------------------------------------

        /**
         * @brief
         * ThreadBase - base thread class.
         * 
         * @version 1.0
         * @authors Denis Z. (code4un@yandex.ru)
        **/
        class ThreadBase : public ctul_IThread
        {

        private:

            // -----------------------------------------------------------

            // ===========================================================
            // DELETED
            // ===========================================================

            ThreadBase(const ThreadBase&) = delete;
            ThreadBase& operator=(const ThreadBase&) = delete;
            ThreadBase(ThreadBase&&) = delete;
            ThreadBase& operator=(ThreadBase&&) = delete;

            // -----------------------------------------------------------

        protected:

            // -----------------------------------------------------------

            // ===========================================================
            // CONSTANTS
            // ===========================================================

            /** Thread-ID. **/
            const thread_id_t mID;

            // ===========================================================
            // FIELDS
            // ===========================================================

            /** Current State. **/
            ctul_atomic<byte_t> mState;

            /** IThreadListener. **/
            ctul_IThreadListener* mEventsListener;

            // ===========================================================
            // CONSTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ThreadBase constructor.
             * 
             * @param pID - thread id.
             * @throws - can throw exception:
             *  - out-of-memory;
            **/
            explicit ThreadBase(const thread_id_t pID);

            // -----------------------------------------------------------

        public:

            // -----------------------------------------------------------

            // ===========================================================
            // DESTRUCTOR
            // ===========================================================

            /**
             * @brief
             * ThreadBase destructor.
             * 
             * @throws - can throw exception:
             *  - mutex;
             *  - access-violation;
            **/
            virtual ~ThreadBase();

            // ===========================================================
            // GETTERS & SETTERS
            // ===========================================================

            /**
             * Returns Thread-ID.
             *
             * @thread_safety - thread-safe (constant).
             * @returns - Thread-ID.
             * @throws - can throw exception.
            **/
            virtual thread_id_t GetID() const final;

            /**
             * @brief
             * Returns current thread state.
             *
             * @thread_safety - not thread-safe.
             * @returns - thread-state.
             * @throws - can throw exception.
            **/
            virtual byte_t GetState() const final;

            /**
             * @brief
             * Set/remove IThread events listener/handler.
             *
             * @thread_safety - must be called before starting this thread.
             * @param pLsitener - IThreadListener implementation.
             * @throws - no exceptions.
            **/
            virtual void SetListener(ctul_IThreadListener* const pListener) final;

            // -----------------------------------------------------------

        }; /// ctul::core::ThreadBase

        // -----------------------------------------------------------

    } /// ctul::core

} /// ctul
using ctul_ThreadBase = ctul::core::ThreadBase;
#define CTUL_CORE_THREAD_BASE_DECL

// -----------------------------------------------------------

#endif // !CTUL_CORE_THREAD_BASE_HPP