#ifndef VINYL_INPUT_H_
#define VINYL_INPUT_H_

#include <vinyl/iinput.h>

namespace vinyl
{
	namespace input
	{
		class VINYL_EXPORT Input : public IInput
		{
		public:
			Input() noexcept;
			virtual ~Input() noexcept;

			virtual void open() noexcept(false);
			virtual void close() noexcept;

			virtual void setCaptureObject(WindHandle window) noexcept;
			virtual WindHandle getCaptureObject() const noexcept;

			virtual void addInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void removeInputListener(const IInputControllerPtr& listener) noexcept override;
			virtual void clearInputListener() noexcept override;

			virtual bool sendInputEvent(const InputEvent& event) noexcept override;

			virtual void reset() noexcept override;

			virtual IInputPtr clone() const noexcept override;

		private:
			Input(const Input&) noexcept = delete;
			Input& operator=(const Input&) noexcept = delete;

		private:
			IInputDevicePtr inputDevice_;
		};
	}
}

#endif