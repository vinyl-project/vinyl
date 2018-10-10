#include "msw_input_device.h"

namespace vinyl
{
	namespace input
	{
		InputKey::Code VirtualKeyToScanCode(HWND hwnd, WPARAM wParam, LPARAM lParam)
		{
			UINT flags = HIWORD(lParam);

			if (flags & 0x100)
			{
				switch (MapVirtualKey(flags & 0xFF, 1))
				{
				case VK_INSERT:   return InputKey::Code::Insert;
				case VK_END:      return InputKey::Code::End;
				case VK_DOWN:     return InputKey::Code::ArrowDown;
				case VK_LEFT:     return InputKey::Code::ArrowLeft;
				case VK_RIGHT:    return InputKey::Code::ArrowRight;
				case VK_UP:       return InputKey::Code::ArrowUp;
				case VK_NEXT:     return InputKey::Code::PageDown;
				case VK_CLEAR:    return InputKey::Code::None;
				case VK_HOME:     return InputKey::Code::Home;
				case VK_PRIOR:    return InputKey::Code::PageUp;
				case VK_DIVIDE:   return InputKey::Code::KP_Divide;
				case VK_MULTIPLY: return InputKey::Code::KP_Multiply;
				case VK_SUBTRACT: return InputKey::Code::KP_Subtract;
				case VK_ADD:      return InputKey::Code::KP_Add;
				case VK_DELETE:   return InputKey::Code::Delete;
				}
			}

			DWORD scan_code;

			switch (wParam)
			{
			case VK_SHIFT:
			{
				scan_code = MapVirtualKey(VK_RSHIFT, 0);
				if ((DWORD)(lParam & 0x01ff0000 >> 16) == scan_code)
				{
					return InputKey::Code::RightShift;
				}

				return InputKey::Code::LeftShift;
			}
			case VK_CONTROL:
			{
				if (lParam & 0x01000000)
				{
					return InputKey::Code::RightControl;
				}

				DWORD time = (DWORD)::GetMessageTime();

				MSG msg;
				if (PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE))
				{
					if (msg.message == WM_KEYDOWN || msg.message == WM_SYSKEYDOWN)
					{
						if (msg.wParam == VK_MENU &&
							msg.lParam & 0x01000000 &&
							msg.time == time)
						{
							return InputKey::Code::None;
						}
					}
				}

				return InputKey::Code::LeftControl;
			}

			case VK_MENU:
			{
				if (lParam & 0x01000000)
					return InputKey::Code::RightAlt;

				return InputKey::Code::LeftAlt;
			}

			case VK_RETURN:
			{
				if (lParam & 0x01000000)
				{
					return InputKey::Code::Enter;
				}

				return InputKey::Code::Enter;
			}
			case VK_ESCAPE:        return InputKey::Code::Escape;
			case VK_TAB:           return InputKey::Code::Tab;
			case VK_BACK:          return InputKey::Code::Backspace;
			case VK_HOME:          return InputKey::Code::Home;
			case VK_END:           return InputKey::Code::End;
			case VK_PRIOR:         return InputKey::Code::PageUp;
			case VK_NEXT:          return InputKey::Code::PageDown;
			case VK_INSERT:        return InputKey::Code::Insert;
			case VK_DELETE:        return InputKey::Code::Delete;
			case VK_LEFT:          return InputKey::Code::ArrowLeft;
			case VK_UP:            return InputKey::Code::ArrowUp;
			case VK_RIGHT:         return InputKey::Code::ArrowRight;
			case VK_DOWN:          return InputKey::Code::ArrowDown;
			case VK_F1:            return InputKey::Code::F1;
			case VK_F2:            return InputKey::Code::F2;
			case VK_F3:            return InputKey::Code::F3;
			case VK_F4:            return InputKey::Code::F4;
			case VK_F5:            return InputKey::Code::F5;
			case VK_F6:            return InputKey::Code::F6;
			case VK_F7:            return InputKey::Code::F7;
			case VK_F8:            return InputKey::Code::F8;
			case VK_F9:            return InputKey::Code::F9;
			case VK_F10:           return InputKey::Code::F10;
			case VK_F11:           return InputKey::Code::F11;
			case VK_F12:           return InputKey::Code::F12;
			case VK_F13:           return InputKey::Code::F13;
			case VK_F14:           return InputKey::Code::F14;
			case VK_F15:           return InputKey::Code::F15;
			case VK_F16:           return InputKey::Code::F16;
			case VK_F17:           return InputKey::Code::F17;
			case VK_F18:           return InputKey::Code::F18;
			case VK_F19:           return InputKey::Code::F19;
			case VK_F20:           return InputKey::Code::F20;
			case VK_F21:           return InputKey::Code::F21;
			case VK_F22:           return InputKey::Code::F22;
			case VK_F23:           return InputKey::Code::F23;
			case VK_F24:           return InputKey::Code::F24;

			case VK_SPACE:         return InputKey::Code::Space;

			case VK_NUMPAD0:       return InputKey::Code::KP_0;
			case VK_NUMPAD1:       return InputKey::Code::KP_1;
			case VK_NUMPAD2:       return InputKey::Code::KP_2;
			case VK_NUMPAD3:       return InputKey::Code::KP_3;
			case VK_NUMPAD4:       return InputKey::Code::KP_4;
			case VK_NUMPAD5:       return InputKey::Code::KP_5;
			case VK_NUMPAD6:       return InputKey::Code::KP_6;
			case VK_NUMPAD7:       return InputKey::Code::KP_7;
			case VK_NUMPAD8:       return InputKey::Code::KP_8;
			case VK_NUMPAD9:       return InputKey::Code::KP_9;

			case VK_DIVIDE:        return InputKey::Code::KP_Divide;
			case VK_MULTIPLY:      return InputKey::Code::KP_Multiply;
			case VK_SUBTRACT:      return InputKey::Code::KP_Subtract;
			case VK_ADD:           return InputKey::Code::KP_Add;
			case VK_DECIMAL:       return InputKey::Code::KP_Decimal;
			case VK_NUMLOCK:       return InputKey::Code::NumLock;

			case VK_CAPITAL:       return InputKey::Code::CapsLock;
			case VK_SCROLL:        return InputKey::Code::ScrollLock;
			case VK_PAUSE:         return InputKey::Code::Pause;

			case VK_LWIN:          return InputKey::Code::Menu;
			case VK_RWIN:          return InputKey::Code::Menu;
			case VK_APPS:          return InputKey::Code::None;
			}

			if (wParam >= 'a' && wParam <= 'z')
			{
				return (InputKey::Code)(InputKey::Code::A + wParam - 'a');
			}

			if (wParam >= 'A' && wParam <= 'Z')
			{
				return (InputKey::Code)(InputKey::Code::A + wParam - 'A');
			}

			if (wParam >= '0' && wParam <= '9')
			{
				return (InputKey::Code)(InputKey::Code::Key0 + wParam - '0');
			}

			return InputKey::Code::None;
		}

		int VirtualKeyToText(WPARAM _virtualKey)
		{
			static WCHAR deadKey = 0;

			BYTE keyState[256];
			HKL  layout = GetKeyboardLayout(0);
			if (GetKeyboardState(keyState) == 0)
				return 0;

			WCHAR buff[3] = { 0, 0, 0 };
			int ascii = ToUnicodeEx((UINT)_virtualKey, 0, keyState, buff, 3, 0, layout);
			if (ascii == 1 && deadKey != '\0')
			{
				// A dead key is stored and we have just converted a character key
				// Combine the two into a single character
				WCHAR wcBuff[3] = { buff[0], deadKey, '\0' };
				WCHAR out[3];

				deadKey = '\0';
				if (FoldStringW(MAP_PRECOMPOSED, (LPWSTR)wcBuff, 3, (LPWSTR)out, 3))
					return out[0];
			}
			else if (ascii == 1)
			{
				// We have a single character
				deadKey = '\0';
				return buff[0];
			}
			else if (ascii == 2)
			{
				// Convert a non-combining diacritical mark into a combining diacritical mark
				// Combining versions range from 0x300 to 0x36F; only 5 (for French) have been mapped below
				// http://www.fileformat.info/info/unicode/block/combining_diacritical_marks/images.htm
				switch (buff[0])
				{
				case 0x5E: // Circumflex accent: §Ó
					deadKey = 0x302;
					break;
				case 0x60: // Grave accent: §Ñ
					deadKey = 0x300;
					break;
				case 0xA8: // Diaeresis: §E
					deadKey = 0x308;
					break;
				case 0xB4: // Acute accent: §Û
					deadKey = 0x301;
					break;
				case 0xB8: // Cedilla: §Ù
					deadKey = 0x327;
					break;
				default:
					deadKey = buff[0];
					break;
				}
			}
			return 0;
		}

		MSWInputDevice::MSWInputDevice() noexcept
		{
		}

		MSWInputDevice::~MSWInputDevice() noexcept
		{
		}

		IInputDevicePtr
		MSWInputDevice::clone() const noexcept
		{
			return std::make_shared<MSWInputDevice>();
		}
	}
}