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
		input->open(profile);

		input_ = std::move(input);
	}
	else
	{
		throw std::runtime_error("Vinyl does not initialized.");
	}
}

void VINYL_C_CALL VinylNewWindow(const char* path, vinyl::input::WindHandle& win) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeNewWindow(path, win));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindWindowFromPos(std::uint16_t x, std::uint16_t y, vinyl::input::WindHandle& win) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindWindowFromPos(x, y, win));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindWindowFromTitle(const char* tile, vinyl::input::WindHandle& win) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindWindowFromTitle(tile, win));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindWindowFromClassName(const char* tile, vinyl::input::WindHandle& win) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindWindowFromClassName(tile, win));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyDown(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyDown(win, key));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyUp(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyUp(win, key));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylKeyClick(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false)
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyDown(win, key));
		input_->sendInputEvent(vinyl::input::InputEvent::makeKeyUp(win, key));
	}
	else
	{
		throw std::runtime_error("Vinyl does not initialized.");
	}
}

void VINYL_C_CALL VinylKeyDoubleClick(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key) noexcept(false)
{
	VinylKeyClick(win, key);
	VinylKeyClick(win, key);
}

void VINYL_C_CALL VinylWaitKey(vinyl::input::WindHandle win, vinyl::input::InputKey::Code& key) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWaitKey(win, key));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsKeyDown(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsKeyDown(win, key, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsKeyUp(vinyl::input::WindHandle win, vinyl::input::InputKey::Code key, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsKeyUp(win, key, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseMove(vinyl::input::WindHandle win, std::int32_t x, std::int32_t y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseMove(win, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseMoveTo(vinyl::input::WindHandle win, std::int32_t x, std::int32_t y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseMoveTo(win, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonDown(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonDown(win, button, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonUp(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonUp(win, button, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylMouseButtonClick(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false)
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonDown(win, button, x, y));
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseButtonUp(win, button, x, y));
	}
	else
	{
		throw std::runtime_error("Vinyl does not initialized.");
	}
}

void VINYL_C_CALL VinylMouseButtonDoubleClick(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint32_t x, std::uint32_t y) noexcept(false)
{
	VinylMouseButtonClick(win, button, x, y);
	VinylMouseButtonClick(win, button, x, y);
}

void VINYL_C_CALL VinylIsMouseButtonDown(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsMouseButtonDown(win, button, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylIsMouseButtonUp(vinyl::input::WindHandle win, vinyl::input::InputButton::Code button, std::uint8_t& state) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeIsMouseButtonUp(win, button, state));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWaitMouseButton(vinyl::input::WindHandle win, vinyl::input::InputButton::Code& button) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWaitButton(win, button));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWheelUp(vinyl::input::WindHandle win) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseWheelUp(win));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylWheelDown(vinyl::input::WindHandle win) noexcept(false)
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMouseWheelDown(win));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylGetMousePos(vinyl::input::WindHandle win, std::int16_t& x, std::int16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeGetMousePos(win, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylGetWindowPos(vinyl::input::WindHandle win, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeGetWindowSize(win, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylGetWindowSize(vinyl::input::WindHandle win, std::uint16_t& w, std::uint16_t& h) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeGetWindowSize(win, w, h));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylGetWindowTitle(vinyl::input::WindHandle win, char* title) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeGetWindowTitle(win, title));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylGetWindowClassName(vinyl::input::WindHandle win, char* classname) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeGetWindowClassName(win, classname));
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

void VINYL_C_CALL VinylMessageBox(vinyl::input::WindHandle win, const char* message) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeMessageBox(win, message));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylSayString(vinyl::input::WindHandle win, const char* message) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeSayString(win, message));
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

void VINYL_C_CALL VinylFindColor(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindColor(image, w, h, r, g, b, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindColorEx(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindColorEx(image, w, h, r, g, b, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindCenterColor(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindCenterColor(image, w, h, r, g, b, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylFindImage(const std::uint8_t* image, std::uint16_t w, std::uint16_t h, const std::uint8_t* pattern, std::uint16_t w_, std::uint16_t h_, std::uint16_t& x, std::uint16_t& y) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeFindImage(image, w, h, pattern, w_, h_, x, y));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylScreenshot(vinyl::input::WindHandle win, std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint8_t* data) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeScreenshot(win, x, y, w, h, data));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylStartRecord(const char* filepath) noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeStartRecord(filepath));
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylPauseRecord() noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makePauseRecord());
	else
		throw std::runtime_error("Vinyl does not initialized.");
}

void VINYL_C_CALL VinylStopRecord() noexcept(false)
{
	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeStopRecord());
	else
		throw std::runtime_error("Vinyl does not initialized.");
}