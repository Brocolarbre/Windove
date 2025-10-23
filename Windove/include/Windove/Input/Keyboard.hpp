#pragma once

#include "Modifiers.hpp"

namespace dove
{
	class Window;

	class Keyboard
	{
	public:
		enum class Key
		{
			None = -1,
			Space,
			Apostrophe,
			Comma,
			Minus,
			Period,
			Slash,
			Zero,
			One,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Nine,
			Semicolon,
			Equal,
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			LeftBracket,
			Backslash,
			RightBracket,
			GraveAccent,
			World1,
			World2,
			Escape,
			Enter,
			Tab,
			Backspace,
			Insert,
			Delete,
			Right,
			Left,
			Down,
			Up,
			PageUp,
			PageDown,
			Home,
			End,
			CapsLock,
			ScrollLock,
			NumLock,
			PrintScreen,
			Pause,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F15,
			F16,
			F17,
			F18,
			F19,
			F20,
			F21,
			F22,
			F23,
			F24,
			F25,
			Numpad0,
			Numpad1,
			Numpad2,
			Numpad3,
			Numpad4,
			Numpad5,
			Numpad6,
			Numpad7,
			Numpad8,
			Numpad9,
			NumpadDecimal,
			NumpadDivide,
			NumpadMultiply,
			NumpadSubtract,
			NumpadAdd,
			NumpadEnter,
			NumpadEqual,
			LeftShift,
			LeftControl,
			LeftAlt,
			LeftSuper,
			RightShift,
			RightControl,
			RightAlt,
			RightSuper,
			Menu
		};

		WINDOVE_API static Keyboard::Key getKey(int key);
		WINDOVE_API static int getPlatformKey(Keyboard::Key key);

		WINDOVE_API static bool isKeyPressed(Window& window, Keyboard::Key key);
		WINDOVE_API static bool isKeyReleased(Window& window, Keyboard::Key key);
		WINDOVE_API static bool isKeyRepeated(Window& window, Keyboard::Key key);

		WINDOVE_API static int getKeyScancode(Keyboard::Key key);
		WINDOVE_API static std::string getKeyName(Keyboard::Key key);

		WINDOVE_API static std::string getClipboardContent();
		WINDOVE_API static void setClipboardContent(const std::string& clipboardContent);
	};

	struct KeyEvent
	{
		Keyboard::Key key;
		Modifiers::InputModifiers modifiers;
	};
}