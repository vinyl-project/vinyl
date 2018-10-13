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
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyDown(key, 10));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyUp(vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyUp(key, 10));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyClick(vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyDown(key, 10));
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyUp(key, 10));
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
		input_->sendInputEvent(vinyl::input::InputEvent::makeWaitKey(key));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsKeyDown(vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsKeyDown(key, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsKeyUp(vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsKeyUp(key, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseMove(float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseMove(x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseMoveTo(float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseMoveTo(x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonDown(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonDown(button, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonUp(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonUp(button, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonClick(vinyl::input::InputButton::Code button, float x, float y) noexcept(false)
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonDown(button, x, y));
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonUp(button, x, y));
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

void VINYL_C_CALL VinylIsMouseButtonDown(vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsMouseButtonDown(button, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsMouseButtonUp(vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsMouseButtonUp(button, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWaitMouseButton(vinyl::input::InputButton::Code button) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWaitButton(button));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWheelUp() noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseWheelUp());
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWheelDown() noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseWheelDown());
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylGetDesktopSize(std::uint16_t& w, std::uint16_t& h) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeGetDesktopSize(w, h));
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

void VINYL_C_CALL VinylSayString(const char* message) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeSayString(message));
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

void VINYL_C_CALL VinylFindColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindColor(r, g, b, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindColorEx(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindColorEx(r, g, b, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindCenterColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindCenterColor(r, g, b, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindImage(std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindImage(image, w, h, x, y));
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