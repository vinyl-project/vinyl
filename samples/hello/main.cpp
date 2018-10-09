#include <vinyl/input.h>

using namespace vinyl;

int main(int argc, const char* argv[])
{
	auto input = std::make_shared<vinyl::input::DefaultInput>();
	input->open();
	input->sendInputEvent(input::InputEvent::makeWindowKeyDown(input::InputKey::Code::A, 0, 0));
	input->sendInputEvent(input::InputEvent::makeWindowMouseMotion(100, 100));

	return 0;
}