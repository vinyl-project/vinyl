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
		Input::Input() noexcept
		{
		}

		Input::~Input() noexcept
		{
			this->close();
		}

		void
		Input::open() noexcept(false)
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
		Input::close() noexcept
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
		Input::setCaptureObject(WindHandle window) noexcept
		{
			if (inputDevice_)
				inputDevice_->setCaptureObject(window);
		}

		WindHandle
		Input::getCaptureObject() const noexcept
		{
			if (inputDevice_)
				return inputDevice_->getCaptureObject();
			return nullptr;
		}

		void
		Input::obtainMouseCapture() noexcept
		{
			if (mouseCaptureDevice_ && !mouseCaptureDevice_->capture())
				mouseCaptureDevice_->obtainCaptures();
		}

		void
		Input::obtainKeyboardCapture() noexcept
		{
			if (keyboardCaptureDevice_ && !keyboardCaptureDevice_->capture())
				keyboardCaptureDevice_->obtainCaptures();
		}

		void
		Input::obtainMouseCapture(const IInputMousePtr& mouse) noexcept
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
		Input::obtainMouseCapture(IInputMousePtr&& mouse) noexcept
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
		Input::obtainKeyboardCapture(const IInputKeyboardPtr& keyboard) noexcept
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
		Input::obtainKeyboardCapture(IInputKeyboardPtr&& keyboard) noexcept
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
		Input::obtainCaptures() noexcept
		{
			this->obtainMouseCapture();
			this->obtainKeyboardCapture();
		}

		void
		Input::releaseMouseCapture() noexcept
		{
			if (mouseCaptureDevice_ && mouseCaptureDevice_->capture())
				mouseCaptureDevice_->releaseCapture();
		}

		void
		Input::releaseKeyboardCapture() noexcept
		{
			if (keyboardCaptureDevice_ && keyboardCaptureDevice_->capture())
				keyboardCaptureDevice_->releaseCapture();
		}

		void
		Input::releaseCapture() noexcept
		{
			this->releaseMouseCapture();
			this->releaseKeyboardCapture();
		}

		void
		Input::reset() noexcept
		{
			if (mouseCaptureDevice_)
				mouseCaptureDevice_->reset();

			if (keyboardCaptureDevice_)
				keyboardCaptureDevice_->reset();
		}

		void
		Input::addInputListener(const IInputControllerPtr& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->addInputListener(listener);
		}

		void
		Input::addInputListener(IInputControllerPtr&& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->addInputListener(std::move(listener));
		}

		void
		Input::removeInputListener(const IInputControllerPtr& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->removeInputListener(listener);
		}

		void
		Input::removeInputListener(IInputControllerPtr&& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->removeInputListener(std::move(listener));
		}

		void
		Input::clearInputListener() noexcept
		{
			if (inputDevice_)
				inputDevice_->clearInputListener();
		}

		bool
		Input::sendInputEvent(const InputEvent& event) noexcept
		{
			if (inputDevice_)
				return inputDevice_->sendEvent(event);
			return false;
		}

		IInputPtr
		Input::clone() const noexcept
		{
			auto input = std::make_shared<Input>();
			input->open();

			if (keyboardCaptureDevice_)
				input->obtainKeyboardCapture(keyboardCaptureDevice_->clone());

			if (mouseCaptureDevice_)
				input->obtainMouseCapture(mouseCaptureDevice_->clone());

			return input;
		}
	}
}