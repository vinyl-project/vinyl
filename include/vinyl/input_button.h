#ifndef VINYL_INPUT_BUTTON_H_
#define VINYL_INPUT_BUTTON_H_

#include <vinyl/input_button.h>

namespace vinyl
{
	namespace input
	{
		class InputButton
		{
		public:
			using Type = float;

			enum Code : std::uint8_t
			{
				Left = 0,
				Right,
				Middle,

				Mouse0 = Left,
				Mouse1 = Right,
				Mouse2 = Middle,
				Mouse3,
				Mouse4,
				Mouse5,
				Mouse6,
				Mouse7,
				Mouse8,
				MouseWheel,
				MouseX,
				MouseY,
				MouseZ,
				MouseLast,

				NumButtonCodes,
			};
		};

		class InputAxis
		{
		public:
			enum Code
			{
				MouseX,
				MouseY,

				Horizontal,
				Vertical,

				NumAxisCodes,
			};
		};
	}
}

#endif