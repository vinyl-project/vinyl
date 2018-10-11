#ifndef VINYL_INPUT_DEBUG_H_
#define VINYL_INPUT_DEBUG_H_

#include <vinyl/iinput_debug.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT InputDebug : public IInputDebug
		{
		public:
			InputDebug() noexcept;
			virtual ~InputDebug() noexcept;

			virtual IInputDebugPtr clone() const noexcept override;

		protected:
			virtual void onInputEvent(const InputEvent& event) noexcept override;

		private:
			InputDebug(const InputDebug&) noexcept = delete;
			InputDebug& operator=(const InputDebug&) noexcept = delete;

		private:
			bool tracePrint_;
		};
	}
}

#endif