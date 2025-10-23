#pragma once

#include "Modifiers.hpp"

#include <vector>

struct GLFWcursor;

namespace dove
{
	class Window;
	struct Vector2;

	class Mouse
	{
	public:
		enum class Button
		{
			None = -1,
			One,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Last = Eight,
			Left = One,
			Right = Two,
			Middle = Three
		};

		enum class CursorMode
		{
			Normal = 0,
			Hidden,
			Disabled
		};

		class Cursor
		{
		private:
			GLFWcursor* m_cursor;

		public:
			WINDOVE_API Cursor(unsigned int width, unsigned int height, std::vector<unsigned char>& image, const Vector2& hotspot);
			WINDOVE_API Cursor(const Cursor& cursor) = delete;
			WINDOVE_API Cursor(Cursor&& cursor) noexcept;
			WINDOVE_API ~Cursor();

			WINDOVE_API Cursor& operator=(const Cursor& cursor) = delete;
			WINDOVE_API Cursor& operator=(Cursor&& cursor) noexcept;

			WINDOVE_API void setActive(Window& window);
			WINDOVE_API void setStandard(Window& window);

			WINDOVE_API static void reset(Window& window);
		};

		WINDOVE_API static Mouse::Button getButton(int button);
		WINDOVE_API static int getPlatformButton(Mouse::Button button);

		WINDOVE_API static bool isKeyPressed(Window& window, Mouse::Button button);
		WINDOVE_API static bool isKeyReleased(Window& window, Mouse::Button button);

		WINDOVE_API static void setCursorMode(Window& window, CursorMode cursorMode);
		WINDOVE_API static void enableRawMotion(Window& window, bool enable);
		WINDOVE_API static void enableStickyKeys(Window& window, bool enable);
		WINDOVE_API static void enableStickyMouseButtons(Window& window, bool enable);
		WINDOVE_API static void lockKeyModifiers(Window& window, bool lock);

		WINDOVE_API static Vector2 getPosition(Window& window);
	};

	struct MouseEvent
	{
		Mouse::Button button;
		Modifiers::InputModifiers modifiers;
		unsigned int x;
		unsigned int y;
	};
}