#include <vinyl/input.h>
#include <vinyl/input_device.h>
#include <vinyl/input_debug.h>

#if defined(VINYL_FEATURE_INPUT_API_WINDOWS)
#	include "msw_input_keyboard.h"
#	include "msw_input_mouse.h"
#	include "msw_input_window.h"
#	include "msw_input_image.h"
#	include "msw_input_record.h"
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
		Input::open(const char* profile) noexcept(false)
		{
#if defined(VINYL_FEATURE_INPUT_API_WINDOWS)
			inputDevice_ = std::make_shared<InputDevice>();

			if (profile)
				SetCurrentDirectory(profile);

			this->addInputListener(std::make_shared<MSWInputWindow>());
			this->addInputListener(std::make_shared<InputDebug>());
			this->addInputListener(std::make_shared<MSWInputMouse>());
			this->addInputListener(std::make_shared<MSWInputKeyboard>());
			this->addInputListener(std::make_shared<MSWInputImage>());
			this->addInputListener(std::make_shared<MSWInputRecord>());
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
		Input::reset() noexcept
		{
			if (inputDevice_)
				inputDevice_->reset();
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
			input->open(nullptr);

			return input;
		}
	}
}