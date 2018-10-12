#include <vinyl/vinyl-c.h>
#include <vinyl/input.h>
#include <thread>
#include <stdexcept>

vinyl::input::IInputPtr input_;

void VINYL_C_CALL VinylInit(const char* profile) noexcept(false)
{
	if (!input_)
	{
		auto input = std::make_shared<vinyl::input::Input>();
		input->open();

		input_ = std::move(input);
	}
	else
	{
		throw std::runtime_error("Vinyl does not initialized.");
	}
}

void VINYL_C_CALL VinylKeyDown(vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyDown(key, 10));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyUp(vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyUp(key, 10));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyClick(vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyDown(key, 10));
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyUp(key, 10));
	}
	else
	{
		throw std::runtime_error("Vinyl does not initialized.");
	}
}

void VINYL_C_CALL VinylKeyDoubleClick(vinyl::input::InputKey::Code key) noexcept(false)
{
	VinylKeyClick(key);
	VinylKeyClick(key);
}

void VINYL_C_CALL VinylWaitKey(vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowWaitKey(key));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsKeyDown(vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowIsKeyDown(key, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsKeyUp(vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowIsKeyUp(key, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseMove(float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseMove(x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseMoveTo(float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseMoveTo(x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonDown(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonDown(button, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonUp(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonUp(button, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonClick(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonDown(button, x, y));
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonUp(button, x, y));
	}
	else
	{
		throw std::runtime_error("Vinyl does not initialized.");
	}
}

void VINYL_C_CALL VinylMouseButtonDoubleClick(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	VinylMouseButtonClick(button, x, y);
	VinylMouseButtonClick(button, x, y);
}

void VINYL_C_CALL VinylIsMouseButtonDown(vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowIsMouseButtonDown(button, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsMouseButtonUp(vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowIsMouseButtonUp(button, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWaitMouseButton(vinyl::input::InputButton::Code button) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowWaitButton(button));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWheelUp() noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseWheelUp());
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWheelDown() noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseWheelDown());
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylSleep(std::uint32_t milliseconds) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeSleep(milliseconds));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMessageBox(const char* message) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMessageBox(message));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylTracePrint(std::uint8_t enable) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeTracePrint(enable));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylCommand(const char* cmd) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeCommand(cmd));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* data) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeScreenshot(x, y, w, h, data));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}