#include <vinyl/vinyl-c.h>

int main(int argc, const char* argv[])
{
	VinylInit(nullptr);
	VinylTracePrint(true);
	VinylMouseMoveTo(20, 20);
	VinylMouseButtonDoubleClick(vinyl::input::InputButton::Left, 0, 0);
	VinylKeyDoubleClick(vinyl::input::InputKey::Code::A);
	VinylMessageBox("Hello World");

	return 0;
}