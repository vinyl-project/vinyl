#include <vinyl/input.h>
#include <vinyl/input_device.h>

#if defined(VINYL_FEATURE_INPUT_API_WINDOWS)
#	include "msw_input_device.h"
#	include "msw_input_keyboard.h"
#	include "msw_input_mouse.h"
#elif defined(VINYL_FEATURE_INPUT_API_ANDROID)
#	include "ndk_input_device.h"
#	include "ndk_input_keyboard.h"
#	include "ndk_input_touch.h"
#else
#	include <vinyl/input_device.h>
#	include <vinyl/input_keyboard.h>
#	include <vinyl/input_mouse.h>
#endif

namespace vinyl
{
	namespace input
	{
		DefaultInput::DefaultInput() noexcept
		{
		}

		DefaultInput::~DefaultInput() noexcept
		{
			this->close();
		}

		void
		DefaultInput::open() noexcept(false)
		{
#if defined(VINYL_FEATURE_INPUT_API_WINDOWS)
			inputDevice_ = std::make_shared<MSWInputDevice>();

			this->obtainMouseCapture(std::make_shared<MSWInputMouse>());
			this->obtainKeyboardCapture(std::make_shared<MSWInputKeyboard>());
#elif defined(VINYL_FEATURE_INPUT_API_ANDROID)
			inputDevice_ = std::make_shared<NDKInputDevice>();

			this->obtainMouseCapture(std::make_shared<NDKInputTouch>());
			this->obtainKeyboardCapture(std::make_shared<NDKInputKeyboard>());
#else
			inputDevice_ = std::make_shared<InputDevice>();

			this->obtainMouseCapture(std::make_shared<InputMouse>());
			this->obtainKeyboardCapture(std::make_shared<InputKeyboard>());
#endif
		}

		void
		DefaultInput::close() noexcept
		{
			if (inputDevice_)
			{
				inputDevice_.reset();
				inputDevice_ = nullptr;
			}

			if (mouseCaptureDevice_)
			{
				mouseCaptureDevice_->releaseCapture();
				mouseCaptureDevice_.reset();
				mouseCaptureDevice_ = nullptr;
			}

			if (keyboardCaptureDevice_)
			{
				keyboardCaptureDevice_->releaseCapture();
				keyboardCaptureDevice_.reset();
				keyboardCaptureDevice_ = nullptr;
			}
		}

		void
		DefaultInput::setCaptureObject(WindHandle window) noexcept
		{
			if (inputDevice_)
				inputDevice_->setCaptureObject(window);
		}

		WindHandle
		DefaultInput::getCaptureObject() const noexcept
		{
			if (inputDevice_)
				return inputDevice_->getCaptureObject();
			return nullptr;
		}

		void
		DefaultInput::obtainMouseCapture() noexcept
		{
			if (mouseCaptureDevice_ && !mouseCaptureDevice_->capture())
				mouseCaptureDevice_->obtainCaptures();
		}

		void
		DefaultInput::obtainKeyboardCapture() noexcept
		{
			if (keyboardCaptureDevice_ && !keyboardCaptureDevice_->capture())
				keyboardCaptureDevice_->obtainCaptures();
		}

		void
		DefaultInput::obtainMouseCapture(const IInputMousePtr& mouse) noexcept
		{
			if (mouseCaptureDevice_ != mouse)
			{
				if (mouseCaptureDevice_)
				{
					mouseCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(mouseCaptureDevice_);
				}

				mouseCaptureDevice_ = mouse;

				if (mouseCaptureDevice_)
				{
					mouseCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(mouseCaptureDevice_);
				}
			}
		}

		void
		DefaultInput::obtainMouseCapture(IInputMousePtr&& mouse) noexcept
		{
			if (mouseCaptureDevice_ != mouse)
			{
				if (mouseCaptureDevice_)
				{
					mouseCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(mouseCaptureDevice_);
				}

				mouseCaptureDevice_ = std::move(mouse);

				if (mouseCaptureDevice_)
				{
					mouseCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(mouseCaptureDevice_);
				}
			}
		}

		void
		DefaultInput::obtainKeyboardCapture(const IInputKeyboardPtr& keyboard) noexcept
		{
			if (keyboardCaptureDevice_ != keyboard)
			{
				if (keyboardCaptureDevice_)
				{
					keyboardCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(keyboard);
				}

				keyboardCaptureDevice_ = keyboard;

				if (keyboardCaptureDevice_)
				{
					keyboardCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(keyboardCaptureDevice_);
				}
			}
		}

		void
		DefaultInput::obtainKeyboardCapture(IInputKeyboardPtr&& keyboard) noexcept
		{
			if (keyboardCaptureDevice_ != keyboard)
			{
				if (keyboardCaptureDevice_)
				{
					keyboardCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(keyboard);
				}

				keyboardCaptureDevice_ = std::move(keyboard);

				if (keyboardCaptureDevice_)
				{
					keyboardCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(keyboardCaptureDevice_);
				}
			}
		}

		void
		DefaultInput::obtainCaptures() noexcept
		{
			this->obtainMouseCapture();
			this->obtainKeyboardCapture();
		}

		void
		DefaultInput::releaseMouseCapture() noexcept
		{
			if (mouseCaptureDevice_ && mouseCaptureDevice_->capture())
				mouseCaptureDevice_->releaseCapture();
		}

		void
		DefaultInput::releaseKeyboardCapture() noexcept
		{
			if (keyboardCaptureDevice_ && keyboardCaptureDevice_->capture())
				keyboardCaptureDevice_->releaseCapture();
		}

		void
		DefaultInput::releaseCapture() noexcept
		{
			this->releaseMouseCapture();
			this->releaseKeyboardCapture();
		}

		void
		DefaultInput::reset() noexcept
		{
			if (mouseCaptureDevice_)
				mouseCaptureDevice_->reset();

			if (keyboardCaptureDevice_)
				keyboardCaptureDevice_->reset();
		}

		void
		DefaultInput::addInputListener(const IInputControllerPtr& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->addInputListener(listener);
		}

		void
		DefaultInput::addInputListener(IInputControllerPtr&& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->addInputListener(std::move(listener));
		}

		void
		DefaultInput::removeInputListener(const IInputControllerPtr& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->removeInputListener(listener);
		}

		void
		DefaultInput::removeInputListener(IInputControllerPtr&& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->removeInputListener(std::move(listener));
		}

		void
		DefaultInput::clearInputListener() noexcept
		{
			if (inputDevice_)
				inputDevice_->clearInputListener();
		}

		bool
		DefaultInput::sendInputEvent(const InputEvent& event) noexcept
		{
			if (inputDevice_)
				return inputDevice_->sendEvent(event);
			return false;
		}

		IInputPtr
		DefaultInput::clone() const noexcept
		{
			auto input = std::make_shared<DefaultInput>();
			input->open();

			if (keyboardCaptureDevice_)
				input->obtainKeyboardCapture(keyboardCaptureDevice_->clone());

			if (mouseCaptureDevice_)
				input->obtainMouseCapture(mouseCaptureDevice_->clone());

			return input;
		}
	}
}