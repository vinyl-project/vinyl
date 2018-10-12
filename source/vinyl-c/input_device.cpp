#include <vinyl/input_device.h>
#include <algorithm> // std::find

namespace vinyl
{
	namespace input
	{
		InputDevice::InputDevice() noexcept
			: enableEventPosting_(true)
		{
		}

		InputDevice::~InputDevice() noexcept
		{
			this->clearInputListener();
		}

		void
		InputDevice::setCaptureObject(WindHandle window) noexcept
		{
		}

		WindHandle
		InputDevice::getCaptureObject() const noexcept
		{
			return nullptr;
		}

		void
		InputDevice::enableEventPosting(bool enable) noexcept
		{
			enableEventPosting_ = enable;
		}

		bool
		InputDevice::enableEventPosting() const noexcept
		{
			return enableEventPosting_;
		}

		void
		InputDevice::addInputListener(const IInputControllerPtr& listener) noexcept
		{
			assert(listener);
			auto it = std::find(inputListeners_.begin(), inputListeners_.end(), listener);
			if (it == inputListeners_.end())
			{
				listener->onAttach();
				inputListeners_.push_back(listener);
			}
		}

		void
		InputDevice::addInputListener(IInputControllerPtr&& listener) noexcept
		{
			assert(listener);
			auto it = std::find(inputListeners_.begin(), inputListeners_.end(), listener);
			if (it == inputListeners_.end())
			{
				listener->onAttach();
				inputListeners_.push_back(std::move(listener));
			}
		}

		void
		InputDevice::removeInputListener(const IInputControllerPtr& listener) noexcept
		{
			assert(listener);
			auto it = std::find(inputListeners_.begin(), inputListeners_.end(), listener);
			if (it != inputListeners_.end())
			{
				listener->onDetach();
				inputListeners_.erase(it);
			}
		}

		void
		InputDevice::removeInputListener(IInputControllerPtr&& listener) noexcept
		{
			assert(listener);
			auto it = std::find(inputListeners_.begin(), inputListeners_.end(), listener);
			if (it != inputListeners_.end())
			{
				listener->onDetach();
				inputListeners_.erase(it);
			}
		}

		void
		InputDevice::clearInputListener() noexcept
		{
			for (auto& listener : inputListeners_)
				listener->onDetach();
			inputListeners_.clear();
		}

		bool
		InputDevice::sendEvent(const InputEvent& event) noexcept
		{
			try
			{
				for (auto& it : inputListeners_)
					it->onInputEvent(event);
				return true;
			}
			catch (...)
			{
				return false;
			}
		}

		bool
		InputDevice::postEvent(const InputEvent& event) noexcept
		{
			if (enableEventPosting_)
			{
				mutex_.lock();
				events_.push(event);
				mutex_.unlock();

				dispose_.notify_one();
			}

			return true;
		}

		bool
		InputDevice::peekEvents(InputEvent& event) noexcept
		{
			return true;
		}

		bool
		InputDevice::pollEvents(InputEvent& event) noexcept
		{
			std::unique_lock<std::mutex> lock(mutex_);
			if (lock)
			{
				if (!events_.empty())
				{
					event = events_.front();
					events_.pop();
					return true;
				}
			}

			return false;
		}

		bool
		InputDevice::waitEvents(InputEvent& event) noexcept
		{
			std::unique_lock<std::mutex> lock(mutex_);
			if (events_.empty())
			{
				dispose_.wait(lock);
			}

			return this->pollEvents(event);
		}

		bool
		InputDevice::waitEvents(InputEvent& event, int timeout) noexcept
		{
			std::unique_lock<std::mutex> lock(mutex_);
			if (events_.empty())
			{
				dispose_.wait_for(lock, std::chrono::milliseconds(timeout));
			}

			return this->pollEvents(event);
		}

		void
		InputDevice::flushEvent() noexcept
		{
			mutex_.lock();
			events_ = std::queue<InputEvent>();
			mutex_.unlock();
		}

		IInputDevicePtr
		InputDevice::clone() const noexcept
		{
			return std::make_shared<InputDevice>();
		}
	}
}