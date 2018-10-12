#include "msw_input_keyboard.h"

namespace vinyl
{
	namespace input
	{
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
			case InputKey::Code::LeftShift:  return VK_SHIFT;
			case InputKey::Code::LeftControl:return VK_CONTROL;
			case InputKey::Code::LeftAlt:    return VK_MENU;
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

			case InputKey::Code::LeftMenu:   return VK_LWIN;
			case InputKey::Code::RightMenu:  return VK_RWIN;
			case InputKey::Code::None:       return VK_APPS;
			default:
				return 0;
			}
		}

		MSWInputKeyboard::MSWInputKeyboard() noexcept
		{
		}

		MSWInputKeyboard::~MSWInputKeyboard() noexcept
		{
		}

		void
		MSWInputKeyboard::onInputEvent(const InputEvent& event) noexcept
		{
			switch (event.event)
			{
			case InputEvent::KeyDown:
			{
				auto vkey = ScanCodeToVirtualKey((InputKey::Code)event.key.keysym.sym);
				keybd_event(vkey, MapVirtualKey(vkey, 0), 0, 0);
				Sleep(event.key.delay);
			}
			break;
			case InputEvent::KeyUp:
			{
				auto vkey = ScanCodeToVirtualKey((InputKey::Code)event.key.keysym.sym);
				keybd_event(vkey, MapVirtualKey(vkey, 0), KEYEVENTF_KEYUP, 0);
				Sleep(event.key.delay);
			}
			break;
			default:
				break;
			}
		}

		IInputKeyboardPtr
		MSWInputKeyboard::clone() const noexcept
		{
			return std::make_shared<MSWInputKeyboard>();
		}
	}
}