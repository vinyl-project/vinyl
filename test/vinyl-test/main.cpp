#include <vinyl/vinyl-c.h>

int main(int argc, const char* argv[])
{
	VinylInit(nullptr);

	std::uint16_t x, y;
	VinylFindColor(11, 18, 26, x, y);

	VinylTracePrint(true);
	VinylMouseMoveTo(nullptr, 20, 20);
	VinylMouseButtonDoubleClick(nullptr, vinyl::input::InputButton::Left, 0, 0);
	VinylKeyDoubleClick(nullptr, vinyl::input::InputKey::Code::A);
	VinylMessageBox(nullptr, "Hello World");

	return 0;
}