#include "Windove/Input/Keyboard.hpp"
#include "Windove/Window.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	Keyboard::Key Keyboard::getKey(int key)
	{
		switch (key)
		{
		case GLFW_KEY_SPACE: return Keyboard::Key::Space; break;
		case GLFW_KEY_APOSTROPHE: return Keyboard::Key::Apostrophe; break;
		case GLFW_KEY_COMMA: return Keyboard::Key::Comma; break;
		case GLFW_KEY_MINUS: return Keyboard::Key::Minus; break;
		case GLFW_KEY_PERIOD: return Keyboard::Key::Period; break;
		case GLFW_KEY_SLASH: return Keyboard::Key::Slash; break;
		case GLFW_KEY_0: return Keyboard::Key::Zero; break;
		case GLFW_KEY_1: return Keyboard::Key::One; break;
		case GLFW_KEY_2: return Keyboard::Key::Two; break;
		case GLFW_KEY_3: return Keyboard::Key::Three; break;
		case GLFW_KEY_4: return Keyboard::Key::Four; break;
		case GLFW_KEY_5: return Keyboard::Key::Five; break;
		case GLFW_KEY_6: return Keyboard::Key::Six; break;
		case GLFW_KEY_7: return Keyboard::Key::Seven; break;
		case GLFW_KEY_8: return Keyboard::Key::Eight; break;
		case GLFW_KEY_9: return Keyboard::Key::Nine; break;
		case GLFW_KEY_SEMICOLON: return Keyboard::Key::Semicolon; break;
		case GLFW_KEY_EQUAL: return Keyboard::Key::Equal; break;
		case GLFW_KEY_A: return Keyboard::Key::A; break;
		case GLFW_KEY_B: return Keyboard::Key::B; break;
		case GLFW_KEY_C: return Keyboard::Key::C; break;
		case GLFW_KEY_D: return Keyboard::Key::D; break;
		case GLFW_KEY_E: return Keyboard::Key::E; break;
		case GLFW_KEY_F: return Keyboard::Key::F; break;
		case GLFW_KEY_G: return Keyboard::Key::G; break;
		case GLFW_KEY_H: return Keyboard::Key::H; break;
		case GLFW_KEY_I: return Keyboard::Key::I; break;
		case GLFW_KEY_J: return Keyboard::Key::J; break;
		case GLFW_KEY_K: return Keyboard::Key::K; break;
		case GLFW_KEY_L: return Keyboard::Key::L; break;
		case GLFW_KEY_M: return Keyboard::Key::M; break;
		case GLFW_KEY_N: return Keyboard::Key::N; break;
		case GLFW_KEY_O: return Keyboard::Key::O; break;
		case GLFW_KEY_P: return Keyboard::Key::P; break;
		case GLFW_KEY_Q: return Keyboard::Key::Q; break;
		case GLFW_KEY_R: return Keyboard::Key::R; break;
		case GLFW_KEY_S: return Keyboard::Key::S; break;
		case GLFW_KEY_T: return Keyboard::Key::T; break;
		case GLFW_KEY_U: return Keyboard::Key::U; break;
		case GLFW_KEY_V: return Keyboard::Key::V; break;
		case GLFW_KEY_W: return Keyboard::Key::W; break;
		case GLFW_KEY_X: return Keyboard::Key::X; break;
		case GLFW_KEY_Y: return Keyboard::Key::Y; break;
		case GLFW_KEY_Z: return Keyboard::Key::Z; break;
		case GLFW_KEY_LEFT_BRACKET: return Keyboard::Key::LeftBracket; break;
		case GLFW_KEY_BACKSLASH: return Keyboard::Key::Backslash; break;
		case GLFW_KEY_RIGHT_BRACKET: return Keyboard::Key::RightBracket; break;
		case GLFW_KEY_GRAVE_ACCENT: return Keyboard::Key::GraveAccent; break;
		case GLFW_KEY_WORLD_1: return Keyboard::Key::World1; break;
		case GLFW_KEY_WORLD_2: return Keyboard::Key::World2; break;
		case GLFW_KEY_ESCAPE: return Keyboard::Key::Escape; break;
		case GLFW_KEY_ENTER: return Keyboard::Key::Enter; break;
		case GLFW_KEY_TAB: return Keyboard::Key::Tab; break;
		case GLFW_KEY_BACKSPACE: return Keyboard::Key::Backspace; break;
		case GLFW_KEY_INSERT: return Keyboard::Key::Insert; break;
		case GLFW_KEY_DELETE: return Keyboard::Key::Delete; break;
		case GLFW_KEY_RIGHT: return Keyboard::Key::Right; break;
		case GLFW_KEY_LEFT: return Keyboard::Key::Left; break;
		case GLFW_KEY_DOWN: return Keyboard::Key::Down; break;
		case GLFW_KEY_UP: return Keyboard::Key::Up; break;
		case GLFW_KEY_PAGE_UP: return Keyboard::Key::PageUp; break;
		case GLFW_KEY_PAGE_DOWN: return Keyboard::Key::PageDown; break;
		case GLFW_KEY_HOME: return Keyboard::Key::Home; break;
		case GLFW_KEY_END: return Keyboard::Key::End; break;
		case GLFW_KEY_CAPS_LOCK: return Keyboard::Key::CapsLock; break;
		case GLFW_KEY_SCROLL_LOCK: return Keyboard::Key::ScrollLock; break;
		case GLFW_KEY_NUM_LOCK: return Keyboard::Key::NumLock; break;
		case GLFW_KEY_PRINT_SCREEN: return Keyboard::Key::PrintScreen; break;
		case GLFW_KEY_PAUSE: return Keyboard::Key::Pause; break;
		case GLFW_KEY_F1: return Keyboard::Key::F1; break;
		case GLFW_KEY_F2: return Keyboard::Key::F2; break;
		case GLFW_KEY_F3: return Keyboard::Key::F3; break;
		case GLFW_KEY_F4: return Keyboard::Key::F4; break;
		case GLFW_KEY_F5: return Keyboard::Key::F5; break;
		case GLFW_KEY_F6: return Keyboard::Key::F6; break;
		case GLFW_KEY_F7: return Keyboard::Key::F7; break;
		case GLFW_KEY_F8: return Keyboard::Key::F8; break;
		case GLFW_KEY_F9: return Keyboard::Key::F9; break;
		case GLFW_KEY_F10: return Keyboard::Key::F10; break;
		case GLFW_KEY_F11: return Keyboard::Key::F11; break;
		case GLFW_KEY_F12: return Keyboard::Key::F12; break;
		case GLFW_KEY_F13: return Keyboard::Key::F13; break;
		case GLFW_KEY_F14: return Keyboard::Key::F14; break;
		case GLFW_KEY_F15: return Keyboard::Key::F15; break;
		case GLFW_KEY_F16: return Keyboard::Key::F16; break;
		case GLFW_KEY_F17: return Keyboard::Key::F17; break;
		case GLFW_KEY_F18: return Keyboard::Key::F18; break;
		case GLFW_KEY_F19: return Keyboard::Key::F19; break;
		case GLFW_KEY_F20: return Keyboard::Key::F20; break;
		case GLFW_KEY_F21: return Keyboard::Key::F21; break;
		case GLFW_KEY_F22: return Keyboard::Key::F22; break;
		case GLFW_KEY_F23: return Keyboard::Key::F23; break;
		case GLFW_KEY_F24: return Keyboard::Key::F24; break;
		case GLFW_KEY_F25: return Keyboard::Key::F25; break;
		case GLFW_KEY_KP_0: return Keyboard::Key::Numpad0; break;
		case GLFW_KEY_KP_1: return Keyboard::Key::Numpad1; break;
		case GLFW_KEY_KP_2: return Keyboard::Key::Numpad2; break;
		case GLFW_KEY_KP_3: return Keyboard::Key::Numpad3; break;
		case GLFW_KEY_KP_4: return Keyboard::Key::Numpad4; break;
		case GLFW_KEY_KP_5: return Keyboard::Key::Numpad5; break;
		case GLFW_KEY_KP_6: return Keyboard::Key::Numpad6; break;
		case GLFW_KEY_KP_7: return Keyboard::Key::Numpad7; break;
		case GLFW_KEY_KP_8: return Keyboard::Key::Numpad8; break;
		case GLFW_KEY_KP_9: return Keyboard::Key::Numpad9; break;
		case GLFW_KEY_KP_DECIMAL: return Keyboard::Key::NumpadDecimal; break;
		case GLFW_KEY_KP_DIVIDE: return Keyboard::Key::NumpadDivide; break;
		case GLFW_KEY_KP_MULTIPLY: return Keyboard::Key::NumpadMultiply; break;
		case GLFW_KEY_KP_SUBTRACT: return Keyboard::Key::NumpadSubtract; break;
		case GLFW_KEY_KP_ADD: return Keyboard::Key::NumpadAdd; break;
		case GLFW_KEY_KP_ENTER: return Keyboard::Key::NumpadEnter; break;
		case GLFW_KEY_KP_EQUAL: return Keyboard::Key::NumpadEqual; break;
		case GLFW_KEY_LEFT_SHIFT: return Keyboard::Key::LeftShift; break;
		case GLFW_KEY_LEFT_CONTROL: return Keyboard::Key::LeftControl; break;
		case GLFW_KEY_LEFT_ALT: return Keyboard::Key::LeftAlt; break;
		case GLFW_KEY_LEFT_SUPER: return Keyboard::Key::LeftSuper; break;
		case GLFW_KEY_RIGHT_SHIFT: return Keyboard::Key::RightShift; break;
		case GLFW_KEY_RIGHT_CONTROL: return Keyboard::Key::RightControl; break;
		case GLFW_KEY_RIGHT_ALT: return Keyboard::Key::RightAlt; break;
		case GLFW_KEY_RIGHT_SUPER: return Keyboard::Key::RightSuper; break;
		case GLFW_KEY_MENU: return Keyboard::Key::Menu; break;
		default: return Keyboard::Key::None; break;
		}
	}

	int Keyboard::getPlatformKey(Keyboard::Key key)
	{
		switch (key)
		{
		case Keyboard::Key::Space: return GLFW_KEY_SPACE; break;
		case Keyboard::Key::Apostrophe: return GLFW_KEY_APOSTROPHE; break;
		case Keyboard::Key::Comma: return GLFW_KEY_COMMA; break;
		case Keyboard::Key::Minus: return GLFW_KEY_MINUS; break;
		case Keyboard::Key::Period: return GLFW_KEY_PERIOD; break;
		case Keyboard::Key::Slash: return GLFW_KEY_SLASH; break;
		case Keyboard::Key::Zero: return GLFW_KEY_0; break;
		case Keyboard::Key::One: return GLFW_KEY_1; break;
		case Keyboard::Key::Two: return GLFW_KEY_2; break;
		case Keyboard::Key::Three: return GLFW_KEY_3; break;
		case Keyboard::Key::Four: return GLFW_KEY_4; break;
		case Keyboard::Key::Five: return GLFW_KEY_5; break;
		case Keyboard::Key::Six: return GLFW_KEY_6; break;
		case Keyboard::Key::Seven: return GLFW_KEY_7; break;
		case Keyboard::Key::Eight: return GLFW_KEY_8; break;
		case Keyboard::Key::Nine: return GLFW_KEY_9; break;
		case Keyboard::Key::Semicolon: return GLFW_KEY_SEMICOLON; break;
		case Keyboard::Key::Equal: return GLFW_KEY_EQUAL; break;
		case Keyboard::Key::A: return GLFW_KEY_A; break;
		case Keyboard::Key::B: return GLFW_KEY_B; break;
		case Keyboard::Key::C: return GLFW_KEY_C; break;
		case Keyboard::Key::D: return GLFW_KEY_D; break;
		case Keyboard::Key::E: return GLFW_KEY_E; break;
		case Keyboard::Key::F: return GLFW_KEY_F; break;
		case Keyboard::Key::G: return GLFW_KEY_G; break;
		case Keyboard::Key::H: return GLFW_KEY_H; break;
		case Keyboard::Key::I: return GLFW_KEY_I; break;
		case Keyboard::Key::J: return GLFW_KEY_J; break;
		case Keyboard::Key::K: return GLFW_KEY_K; break;
		case Keyboard::Key::L: return GLFW_KEY_L; break;
		case Keyboard::Key::M: return GLFW_KEY_M; break;
		case Keyboard::Key::N: return GLFW_KEY_N; break;
		case Keyboard::Key::O: return GLFW_KEY_O; break;
		case Keyboard::Key::P: return GLFW_KEY_P; break;
		case Keyboard::Key::Q: return GLFW_KEY_Q; break;
		case Keyboard::Key::R: return GLFW_KEY_R; break;
		case Keyboard::Key::S: return GLFW_KEY_S; break;
		case Keyboard::Key::T: return GLFW_KEY_T; break;
		case Keyboard::Key::U: return GLFW_KEY_U; break;
		case Keyboard::Key::V: return GLFW_KEY_V; break;
		case Keyboard::Key::W: return GLFW_KEY_W; break;
		case Keyboard::Key::X: return GLFW_KEY_X; break;
		case Keyboard::Key::Y: return GLFW_KEY_Y; break;
		case Keyboard::Key::Z: return GLFW_KEY_Z; break;
		case Keyboard::Key::LeftBracket: return GLFW_KEY_LEFT_BRACKET; break;
		case Keyboard::Key::Backslash: return GLFW_KEY_BACKSLASH; break;
		case Keyboard::Key::RightBracket: return GLFW_KEY_RIGHT_BRACKET; break;
		case Keyboard::Key::GraveAccent: return GLFW_KEY_GRAVE_ACCENT; break;
		case Keyboard::Key::World1: return GLFW_KEY_WORLD_1; break;
		case Keyboard::Key::World2: return GLFW_KEY_WORLD_2; break;
		case Keyboard::Key::Escape: return GLFW_KEY_ESCAPE; break;
		case Keyboard::Key::Enter: return GLFW_KEY_ENTER; break;
		case Keyboard::Key::Tab: return GLFW_KEY_TAB; break;
		case Keyboard::Key::Backspace: return GLFW_KEY_BACKSPACE; break;
		case Keyboard::Key::Insert: return GLFW_KEY_INSERT; break;
		case Keyboard::Key::Delete: return GLFW_KEY_DELETE; break;
		case Keyboard::Key::Right: return GLFW_KEY_RIGHT; break;
		case Keyboard::Key::Left: return GLFW_KEY_LEFT; break;
		case Keyboard::Key::Down: return GLFW_KEY_DOWN; break;
		case Keyboard::Key::Up: return GLFW_KEY_UP; break;
		case Keyboard::Key::PageUp: return GLFW_KEY_PAGE_UP; break;
		case Keyboard::Key::PageDown: return GLFW_KEY_PAGE_DOWN; break;
		case Keyboard::Key::Home: return GLFW_KEY_HOME; break;
		case Keyboard::Key::End: return GLFW_KEY_END; break;
		case Keyboard::Key::CapsLock: return GLFW_KEY_CAPS_LOCK; break;
		case Keyboard::Key::ScrollLock: return GLFW_KEY_SCROLL_LOCK; break;
		case Keyboard::Key::NumLock: return GLFW_KEY_NUM_LOCK; break;
		case Keyboard::Key::PrintScreen: return GLFW_KEY_PRINT_SCREEN; break;
		case Keyboard::Key::Pause: return GLFW_KEY_PAUSE; break;
		case Keyboard::Key::F1: return GLFW_KEY_F1; break;
		case Keyboard::Key::F2: return GLFW_KEY_F2; break;
		case Keyboard::Key::F3: return GLFW_KEY_F3; break;
		case Keyboard::Key::F4: return GLFW_KEY_F4; break;
		case Keyboard::Key::F5: return GLFW_KEY_F5; break;
		case Keyboard::Key::F6: return GLFW_KEY_F6; break;
		case Keyboard::Key::F7: return GLFW_KEY_F7; break;
		case Keyboard::Key::F8: return GLFW_KEY_F8; break;
		case Keyboard::Key::F9: return GLFW_KEY_F9; break;
		case Keyboard::Key::F10: return GLFW_KEY_F10; break;
		case Keyboard::Key::F11: return GLFW_KEY_F11; break;
		case Keyboard::Key::F12: return GLFW_KEY_F12; break;
		case Keyboard::Key::F13: return GLFW_KEY_F13; break;
		case Keyboard::Key::F14: return GLFW_KEY_F14; break;
		case Keyboard::Key::F15: return GLFW_KEY_F15; break;
		case Keyboard::Key::F16: return GLFW_KEY_F16; break;
		case Keyboard::Key::F17: return GLFW_KEY_F17; break;
		case Keyboard::Key::F18: return GLFW_KEY_F18; break;
		case Keyboard::Key::F19: return GLFW_KEY_F19; break;
		case Keyboard::Key::F20: return GLFW_KEY_F20; break;
		case Keyboard::Key::F21: return GLFW_KEY_F21; break;
		case Keyboard::Key::F22: return GLFW_KEY_F22; break;
		case Keyboard::Key::F23: return GLFW_KEY_F23; break;
		case Keyboard::Key::F24: return GLFW_KEY_F24; break;
		case Keyboard::Key::F25: return GLFW_KEY_F25; break;
		case Keyboard::Key::Numpad0: return GLFW_KEY_KP_0; break;
		case Keyboard::Key::Numpad1: return GLFW_KEY_KP_1; break;
		case Keyboard::Key::Numpad2: return GLFW_KEY_KP_2; break;
		case Keyboard::Key::Numpad3: return GLFW_KEY_KP_3; break;
		case Keyboard::Key::Numpad4: return GLFW_KEY_KP_4; break;
		case Keyboard::Key::Numpad5: return GLFW_KEY_KP_5; break;
		case Keyboard::Key::Numpad6: return GLFW_KEY_KP_6; break;
		case Keyboard::Key::Numpad7: return GLFW_KEY_KP_7; break;
		case Keyboard::Key::Numpad8: return GLFW_KEY_KP_8; break;
		case Keyboard::Key::Numpad9: return GLFW_KEY_KP_9; break;
		case Keyboard::Key::NumpadDecimal: return GLFW_KEY_KP_DECIMAL; break;
		case Keyboard::Key::NumpadDivide: return GLFW_KEY_KP_DIVIDE; break;
		case Keyboard::Key::NumpadMultiply: return GLFW_KEY_KP_MULTIPLY; break;
		case Keyboard::Key::NumpadSubtract: return GLFW_KEY_KP_SUBTRACT; break;
		case Keyboard::Key::NumpadAdd: return GLFW_KEY_KP_ADD; break;
		case Keyboard::Key::NumpadEnter: return GLFW_KEY_KP_ENTER; break;
		case Keyboard::Key::NumpadEqual: return GLFW_KEY_KP_EQUAL; break;
		case Keyboard::Key::LeftShift: return GLFW_KEY_LEFT_SHIFT; break;
		case Keyboard::Key::LeftControl: return GLFW_KEY_LEFT_CONTROL; break;
		case Keyboard::Key::LeftAlt: return GLFW_KEY_LEFT_ALT; break;
		case Keyboard::Key::LeftSuper: return GLFW_KEY_LEFT_SUPER; break;
		case Keyboard::Key::RightShift: return GLFW_KEY_RIGHT_SHIFT; break;
		case Keyboard::Key::RightControl: return GLFW_KEY_RIGHT_CONTROL; break;
		case Keyboard::Key::RightAlt: return GLFW_KEY_RIGHT_ALT; break;
		case Keyboard::Key::RightSuper: return GLFW_KEY_RIGHT_SUPER; break;
		case Keyboard::Key::Menu: return GLFW_KEY_MENU; break;
		default: return GLFW_KEY_UNKNOWN; break;
		}
	}

	bool Keyboard::isKeyPressed(Window& window, Keyboard::Key key)
	{
		return glfwGetKey(static_cast<GLFWwindow*>(window.getPlatformWindow()), getPlatformKey(key)) == GLFW_PRESS;
	}

	bool Keyboard::isKeyReleased(Window& window, Keyboard::Key key)
	{
		return glfwGetKey(static_cast<GLFWwindow*>(window.getPlatformWindow()), getPlatformKey(key)) == GLFW_RELEASE;
	}

	bool Keyboard::isKeyRepeated(Window& window, Keyboard::Key key)
	{
		return glfwGetKey(static_cast<GLFWwindow*>(window.getPlatformWindow()), getPlatformKey(key)) == GLFW_REPEAT;
	}

	int Keyboard::getKeyScancode(Keyboard::Key key)
	{
		return glfwGetKeyScancode(getPlatformKey(key));
	}

	std::string Keyboard::getKeyName(Keyboard::Key key)
	{
		return std::string(glfwGetKeyName(getPlatformKey(key), getKeyScancode(key)));
	}

	std::string Keyboard::getClipboardContent()
	{
		return std::string(glfwGetClipboardString(nullptr));
	}

	void Keyboard::setClipboardContent(const std::string& clipboardContent)
	{
		glfwSetClipboardString(nullptr, clipboardContent.c_str());
	}
}
