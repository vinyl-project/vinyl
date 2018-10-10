#include <vinyl/vinyl-c.h>

int main(int argc, const char* argv[])
{
	VinylInit(nullptr);
	VinylMouseMoveTo(20, 20);
	VinylMouseButtonDoubleClick(vinyl::input::InputButton::Left, 0, 0);

	return 0;
}