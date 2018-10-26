#include "msw_input_keyboard.h"

namespace vinyl
{
	namespace input
	{
		InputKey::Code VirtualKeyToScanCode(UINT code)
		{
			switch (code)
			{
			case VK_RSHIFT:   	   return InputKey::Code::RightShift;
			case VK_LSHIFT:   	   return InputKey::Code::LeftShift;
			case VK_RCONTROL: 	   return InputKey::Code::RightControl;
			case VK_LCONTROL: 	   return InputKey::Code::LeftControl;
			case VK_RMENU:    	   return InputKey::Code::RightAlt;
			case VK_LMENU:    	   return InputKey::Code::LeftAlt;
			case VK_LWIN:     	   return InputKey::Code::RightMenu;
			case VK_RWIN:     	   return InputKey::Code::LeftMenu;
			case VK_RETURN:		   return InputKey::Code::Enter;
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
			case VK_APPS:          return InputKey::Code::None;
			case VK_CLEAR:		   return InputKey::Code::None;
			}

			if (code >= 'a' && code <= 'z')
				return (InputKey::Code)(InputKey::Code::A + code - 'a');

			if (code >= 'A' && code <= 'Z')
				return (InputKey::Code)(InputKey::Code::A + code - 'A');

			if (code >= '0' && code <= '9')
				return (InputKey::Code)(InputKey::Code::Key0 + code - '0');

			return InputKey::Code::None;
		}

		BYTE ScanCodeToVirtualKey(InputKey::Code code)
		{
			switch (code)
			{
			case InputKey::Code::Key0:       return '0';
			case InputKey::Code::Key1:       return '1';
			case InputKey::Code::Key2:       return '2';
			case InputKey::Code::Key3:       return '3';
			case InputKey::Code::Key4:       return '4';
			case InputKey::Code::Key5:       return '5';
			case InputKey::Code::Key6:       return '6';
			case InputKey::Code::Key7:       return '7';
			case InputKey::Code::Key8:       return '8';
			case InputKey::Code::Key9:       return '9';
			case InputKey::Code::A:          return 'A';
			case InputKey::Code::B:          return 'B';
			case InputKey::Code::C:          return 'C';
			case InputKey::Code::D:          return 'D';
			case InputKey::Code::E:          return 'E';
			case InputKey::Code::F:          return 'F';
			case InputKey::Code::G:          return 'G';
			case InputKey::Code::H:          return 'H';
			case InputKey::Code::I:          return 'I';
			case InputKey::Code::J:          return 'J';
			case InputKey::Code::K:          return 'K';
			case InputKey::Code::L:          return 'L';
			case InputKey::Code::M:          return 'M';
			case InputKey::Code::N:          return 'N';
			case InputKey::Code::O:          return 'O';
			case InputKey::Code::P:          return 'P';
			case InputKey::Code::Q:          return 'Q';
			case InputKey::Code::R:          return 'R';
			case InputKey::Code::S:          return 'S';
			case InputKey::Code::T:          return 'T';
			case InputKey::Code::U:          return 'U';
			case InputKey::Code::V:          return 'V';
			case InputKey::Code::W:          return 'W';
			case InputKey::Code::X:          return 'X';
			case InputKey::Code::Y:          return 'Y';
			case InputKey::Code::Z:          return 'Z';
			case InputKey::Code::LeftShift:  return VK_LSHIFT;
			case InputKey::Code::LeftControl:return VK_LCONTROL;
			case InputKey::Code::LeftAlt:    return VK_LMENU;
			case InputKey::Code::LeftMenu:   return VK_LWIN;
			case InputKey::Code::RightShift: return VK_RSHIFT;
			case InputKey::Code::RightControl:return VK_RCONTROL;
			case InputKey::Code::RightAlt:   return VK_RMENU;
			case InputKey::Code::RightMenu:  return VK_RWIN;
			case InputKey::Code::Enter: 	 return VK_RETURN;
			case InputKey::Code::Escape:     return VK_ESCAPE;
			case InputKey::Code::Tab:        return VK_TAB;
			case InputKey::Code::Backspace:  return VK_BACK;
			case InputKey::Code::Home:       return VK_HOME;
			case InputKey::Code::End:        return VK_END;
			case InputKey::Code::PageUp:     return VK_PRIOR;
			case InputKey::Code::PageDown:   return VK_NEXT;
			case InputKey::Code::Insert:     return VK_INSERT;
			case InputKey::Code::Delete:     return VK_DELETE;
			case InputKey::Code::ArrowLeft:  return VK_LEFT;
			case InputKey::Code::ArrowUp:    return VK_UP;
			case InputKey::Code::ArrowRight: return VK_RIGHT;
			case InputKey::Code::ArrowDown:  return VK_DOWN;
			case InputKey::Code::F1:         return VK_F1;
			case InputKey::Code::F2:         return VK_F2;
			case InputKey::Code::F3:         return VK_F3;
			case InputKey::Code::F4:         return VK_F4;
			case InputKey::Code::F5:         return VK_F5;
			case InputKey::Code::F6:         return VK_F6;
			case InputKey::Code::F7:         return VK_F7;
			case InputKey::Code::F8:         return VK_F8;
			case InputKey::Code::F9:         return VK_F9;
			case InputKey::Code::F10:        return VK_F10;
			case InputKey::Code::F11:        return VK_F11;
			case InputKey::Code::F12:        return VK_F12;
			case InputKey::Code::F13:        return VK_F13;
			case InputKey::Code::F14:        return VK_F14;
			case InputKey::Code::F15:        return VK_F15;
			case InputKey::Code::F16:        return VK_F16;
			case InputKey::Code::F17:        return VK_F17;
			case InputKey::Code::F18:        return VK_F18;
			case InputKey::Code::F19:        return VK_F19;
			case InputKey::Code::F20:        return VK_F20;
			case InputKey::Code::F21:        return VK_F21;
			case InputKey::Code::F22:        return VK_F22;
			case InputKey::Code::F23:        return VK_F23;
			case InputKey::Code::F24:        return VK_F24;

			case InputKey::Code::Space:      return VK_SPACE;

			case InputKey::Code::KP_0:       return VK_NUMPAD0;
			case InputKey::Code::KP_1:       return VK_NUMPAD1;
			case InputKey::Code::KP_2:       return VK_NUMPAD2;
			case InputKey::Code::KP_3:       return VK_NUMPAD3;
			case InputKey::Code::KP_4:       return VK_NUMPAD4;
			case InputKey::Code::KP_5:       return VK_NUMPAD5;
			case InputKey::Code::KP_6:       return VK_NUMPAD6;
			case InputKey::Code::KP_7:       return VK_NUMPAD7;
			case InputKey::Code::KP_8:       return VK_NUMPAD8;
			case InputKey::Code::KP_9:       return VK_NUMPAD9;

			case InputKey::Code::KP_Divide:  return VK_DIVIDE;
			case InputKey::Code::KP_Multiply:return VK_MULTIPLY;
			case InputKey::Code::KP_Subtract:return VK_SUBTRACT;
			case InputKey::Code::KP_Add:     return VK_ADD;
			case InputKey::Code::KP_Decimal: return VK_DECIMAL;
			case InputKey::Code::NumLock:    return VK_NUMLOCK;

			case InputKey::Code::CapsLock:   return VK_CAPITAL;
			case InputKey::Code::ScrollLock: return VK_SCROLL;
			case InputKey::Code::Pause:      return VK_PAUSE;

			case InputKey::Code::None:       return VK_APPS;
			default:
				return 0;
			}
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
				case 0x5E: // Circumflex accent: в
					deadKey = 0x302;
					break;
				case 0x60: // Grave accent: а
					deadKey = 0x300;
					break;
				case 0xA8: // Diaeresis: E
					deadKey = 0x308;
					break;
				case 0xB4: // Acute accent: й
					deadKey = 0x301;
					break;
				case 0xB8: // Cedilla: з
					deadKey = 0x327;
					break;
				default:
					deadKey = buff[0];
					break;
				}
			}
			return 0;
		}

		HHOOK MSWInputKeyboard::hook_ = nullptr;

		MSWInputKeyboard::MSWInputKeyboard() noexcept
		{
		}

		MSWInputKeyboard::~MSWInputKeyboard() noexcept
		{
		}

		void
		MSWInputKeyboard::onActivate() noexcept
		{
			/*if (!hook_)
			{
				hook_ = SetWindowsHookEx(WH_KEYBOARD, MSWInputKeyboard::KeybdProc, GetModuleHandle("user32"), 0);
			}*/
		}

		void
		MSWInputKeyboard::onDeactivate() noexcept
		{
			/*if (hook_)
			{
				UnhookWindowsHookEx(hook_);
				hook_ = nullptr;
			}*/
		}

		IInputControllerPtr
		MSWInputKeyboard::clone() const noexcept
		{
			return std::make_shared<MSWInputKeyboard>();
		}

		LRESULT
		MSWInputKeyboard::KeybdProc(int code, WPARAM wParam, LPARAM lParam) noexcept
		{
			if (code < 0 || code == HC_NOREMOVE)
				return ::CallNextHookEx(hook_, code, wParam, lParam);

			switch (code)
			{
			case WM_KEYDOWN:
			{
			}
			break;
			case WM_KEYUP:
			{
			}
			break;
			}

			return ::CallNextHookEx(hook_, code, wParam, lParam);
		}

		void
		MSWInputKeyboard::onKeyDown(const KeyboardEvent& event) noexcept
		{
			auto vkey = ScanCodeToVirtualKey((InputKey::Code)event.keysym.sym);
			keybd_event(vkey, (BYTE)MapVirtualKey(vkey, 0), 0, 0);
		}

		void
		MSWInputKeyboard::onKeyUp(const KeyboardEvent& event) noexcept
		{
			auto vkey = ScanCodeToVirtualKey((InputKey::Code)event.keysym.sym);
			keybd_event(vkey, (BYTE)MapVirtualKey(vkey, 0), KEYEVENTF_KEYUP, 0);
		}

		void
		MSWInputKeyboard::onIsKeyDown(const KeyboardEvent& event) noexcept
		{
			if (event.state)
			{
				auto vkey = ScanCodeToVirtualKey((InputKey::Code)event.keysym.sym);
				*event.state = GetAsyncKeyState(vkey) & 0x8000 ? true : false;
			}
		}

		void
		MSWInputKeyboard::onIsKeyUp(const KeyboardEvent& event) noexcept
		{
			if (event.state)
			{
				auto vkey = ScanCodeToVirtualKey((InputKey::Code)event.keysym.sym);
				*event.state = GetAsyncKeyState(vkey) & 0x8000 ? false : true;
			}
		}

		void
		MSWInputKeyboard::onWaitKey(const WaitKeyEvent& event) noexcept
		{
			*event.key = InputKey::Code::None;

			while (*event.key == InputKey::Code::None)
			{
				for (std::size_t i = 0x08; i < 0xFF; i++)
				{
					if (GetAsyncKeyState(i) & 0x8000)
					{
						*event.key = VirtualKeyToScanCode(i);
						if (event.windowID > 0)
						{
							if (event.windowID == (std::uint64_t)GetForegroundWindow())
								break;
						}
						else
						{
							break;
						}
					}
				}

				Sleep(event.delay);
			}
		}
	}
}