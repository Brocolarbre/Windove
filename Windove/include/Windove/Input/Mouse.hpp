#pragma once

#include "Modifiers.hpp"

#include <vector>

struct GLFWcursor;

namespace dove
{
	class Window;
	struct Vector2;

	class WINDOVE_API Mouse
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

		class WINDOVE_API Cursor
		{
		private:
			GLFWcursor* m_cursor;

		public:
			Cursor(unsigned int width, unsigned int height, std::vector<unsigned char>& image, const Vector2& hotspot);
			Cursor(const Cursor& cursor) = delete;
			Cursor(Cursor&& cursor) noexcept;
			~Cursor();

			Cursor& operator=(const Cursor& cursor) = delete;
			Cursor& operator=(Cursor&& cursor) noexcept;

			void setActive(Window& window);
			void setStandard(Window& window);

			static void reset(Window& window);
		};

		static Mouse::Button getButton(int button);
		static int getPlatformButton(Mouse::Button button);

		static bool isKeyPressed(Window& window, Mouse::Button button);
		static bool isKeyReleased(Window& window, Mouse::Button button);

		static void setCursorMode(Window& window, CursorMode cursorMode);
		static void enableRawMotion(Window& window, bool enable);
		static void enableStickyKeys(Window& window, bool enable);
		static void enableStickyMouseButtons(Window& window, bool enable);
		static void lockKeyModifiers(Window& window, bool lock);

		static Vector2 getPosition(Window& window);
	};

	struct MouseEvent
	{
		Mouse::Button button;
		Modifiers::InputModifiers modifiers;
		unsigned int x;
		unsigned int y;
	};
}