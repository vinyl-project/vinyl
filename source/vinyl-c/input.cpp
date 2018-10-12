#include <vinyl/input.h>
#include <vinyl/input_device.h>
#include <vinyl/input_debug.h>

#if defined(VINYL_FEATURE_INPUT_API_WINDOWS)
#	include "msw_input_device.h"
#	include "msw_input_keyboard.h"
#	include "msw_input_mouse.h"
#	include "msw_input_user.h"
#	include "msw_input_image.h"
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

			this->obtainUserCapture(std::make_shared<MSWInputUser>());
			this->obtainDebugCapture(std::make_shared<InputDebug>());
			this->obtainMouseCapture(std::make_shared<MSWInputMouse>());
			this->obtainKeyboardCapture(std::make_shared<MSWInputKeyboard>());
			this->obtainImageCapture(std::make_shared<MSWInputImage>());
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

			if (userCaptureDevice_)
			{
				userCaptureDevice_->releaseCapture();
				userCaptureDevice_.reset();
				userCaptureDevice_ = nullptr;
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

			if (debugCaptureDevice_)
			{
				debugCaptureDevice_->releaseCapture();
				debugCaptureDevice_.reset();
				debugCaptureDevice_ = nullptr;
			}

			if (imageCaptureDevice_)
			{
				imageCaptureDevice_->releaseCapture();
				imageCaptureDevice_.reset();
				imageCaptureDevice_ = nullptr;
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
		Input::obtainUserCapture() noexcept
		{
			if (userCaptureDevice_ && !userCaptureDevice_->capture())
				userCaptureDevice_->obtainCaptures();
		}

		void
		Input::obtainDebugCapture() noexcept
		{
			if (debugCaptureDevice_ && !debugCaptureDevice_->capture())
				debugCaptureDevice_->obtainCaptures();
		}

		void
		Input::obtainImageCapture() noexcept
		{
			if (imageCaptureDevice_ && !imageCaptureDevice_->capture())
				imageCaptureDevice_->obtainCaptures();
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
		Input::obtainUserCapture(const IInputUserPtr& user) noexcept
		{
			if (userCaptureDevice_ != user)
			{
				if (userCaptureDevice_)
				{
					userCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(userCaptureDevice_);
				}

				userCaptureDevice_ = user;

				if (userCaptureDevice_)
				{
					userCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(userCaptureDevice_);
				}
			}
		}

		void
		Input::obtainDebugCapture(const IInputDebugPtr& user) noexcept
		{
			if (debugCaptureDevice_ != user)
			{
				if (debugCaptureDevice_)
				{
					debugCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(debugCaptureDevice_);
				}

				debugCaptureDevice_ = user;

				if (debugCaptureDevice_)
				{
					debugCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(debugCaptureDevice_);
				}
			}
		}

		void
		Input::obtainImageCapture(const IInputImagePtr& image) noexcept
		{
			if (imageCaptureDevice_ != image)
			{
				if (imageCaptureDevice_)
				{
					imageCaptureDevice_->releaseCapture();

					if (inputDevice_)
						inputDevice_->removeInputListener(imageCaptureDevice_);
				}

				imageCaptureDevice_ = image;

				if (imageCaptureDevice_)
				{
					imageCaptureDevice_->obtainCaptures();

					if (inputDevice_)
						inputDevice_->addInputListener(imageCaptureDevice_);
				}
			}
		}

		void
		Input::obtainCaptures() noexcept
		{
			this->obtainMouseCapture();
			this->obtainKeyboardCapture();
			this->obtainUserCapture();
			this->obtainDebugCapture();
			this->obtainImageCapture();
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
		Input::releaseUserCapture() noexcept
		{
			if (userCaptureDevice_ && userCaptureDevice_->capture())
				userCaptureDevice_->releaseCapture();
		}

		void
		Input::releaseDebugCapture() noexcept
		{
			if (debugCaptureDevice_ && debugCaptureDevice_->capture())
				debugCaptureDevice_->releaseCapture();
		}

		void
		Input::releaseImageCapture() noexcept
		{
			if (imageCaptureDevice_ && imageCaptureDevice_->capture())
				imageCaptureDevice_->releaseCapture();
		}

		void
		Input::releaseCaptures() noexcept
		{
			this->releaseMouseCapture();
			this->releaseKeyboardCapture();
			this->releaseUserCapture();
			this->releaseDebugCapture();
			this->releaseImageCapture();
		}

		void
		Input::reset() noexcept
		{
			if (mouseCaptureDevice_)
				mouseCaptureDevice_->reset();

			if (keyboardCaptureDevice_)
				keyboardCaptureDevice_->reset();

			if (userCaptureDevice_)
				userCaptureDevice_->reset();

			if (debugCaptureDevice_)
				debugCaptureDevice_->reset();

			if (imageCaptureDevice_)
				imageCaptureDevice_->reset();
		}

		void
		Input::addInputListener(const IInputControllerPtr& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->addInputListener(listener);
		}

		void
		Input::removeInputListener(const IInputControllerPtr& listener) noexcept
		{
			if (inputDevice_)
				inputDevice_->removeInputListener(listener);
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

			if (userCaptureDevice_)
				input->obtainUserCapture(userCaptureDevice_->clone());

			if (debugCaptureDevice_)
				input->obtainDebugCapture(debugCaptureDevice_->clone());

			if (imageCaptureDevice_)
				input->obtainImageCapture(imageCaptureDevice_->clone());

			return input;
		}
	}
}