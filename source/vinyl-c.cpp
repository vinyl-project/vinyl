#include <vinyl/vinyl-c.h>
#include <vinyl/input.h>

vinyl::input::IInputPtr input_;

bool VINYL_C_CALL VinylInit(const char* profile) noexcept
{
	try
	{
		if (!input_)
		{
			auto input = std::make_shared<vinyl::input::Input>();
			input->open();

			input_ = std::move(input);
			return true;
		}

		return false;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

void VINYL_C_CALL VinylKeyDown(vinyl::input::InputKey::Code key) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyDown(key, 0, 0));
}

void VINYL_C_CALL VinylKeyUp(vinyl::input::InputKey::Code key) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyUp(key, 0, 0));
}

void VINYL_C_CALL VinylKeyClick(vinyl::input::InputKey::Code key) noexcept
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyDown(key, 0, 0));
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowKeyUp(key, 0, 0));
	}
}

void VINYL_C_CALL VinylKeyDoubleClick(vinyl::input::InputKey::Code key) noexcept
{
	VinylKeyClick(key);
	VinylKeyClick(key);
}

void VINYL_C_CALL VinylMouseMove(float x, float y) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseMove(x, y));
}

void VINYL_C_CALL VinylMouseMoveTo(float x, float y) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseMoveTo(x, y));
}

void VINYL_C_CALL VinylMouseButtonDown(vinyl::input::InputButton::Code button, float x, float y) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonDown(button, x, y));
}

void VINYL_C_CALL VinylMouseButtonUp(vinyl::input::InputButton::Code button, float x, float y) noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonUp(button, x, y));
}

void VINYL_C_CALL VinylMouseButtonClick(vinyl::input::InputButton::Code button, float x, float y) noexcept
{
	assert(input_);

	if (input_)
	{
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonDown(button, x, y));
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseButtonUp(button, x, y));
	}
}

void VINYL_C_CALL VinylMouseButtonDoubleClick(vinyl::input::InputButton::Code button, float x, float y) noexcept
{
	VinylMouseButtonClick(button, x, y);
	VinylMouseButtonClick(button, x, y);
}

void VINYL_C_CALL VinylWheelUp() noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseWheelUp());
}

void VINYL_C_CALL VinylWheelDown() noexcept
{
	assert(input_);

	if (input_)
		input_->sendInputEvent(vinyl::input::InputEvent::makeWindowMouseWheelDown());
}

void VINYL_C_CALL VinylScreenshot(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h) noexcept
{
}