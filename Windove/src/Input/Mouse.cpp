#include "Windove/Input/Mouse.hpp"
#include "Windove/Window.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	Mouse::Cursor::Cursor(unsigned int width, unsigned int height, std::vector<unsigned char>& image, const Vector2& hotspot) :
		m_cursor(nullptr)
	{
		GLFWimage imageData{};
		imageData.width = width;
		imageData.height = height;
		imageData.pixels = image.data();

		m_cursor = glfwCreateCursor(&imageData, hotspot.x, hotspot.y);
	}

	Mouse::Cursor::Cursor(Cursor&& cursor) noexcept :
		m_cursor(cursor.m_cursor)
	{
		cursor.m_cursor = nullptr;
	}

	Mouse::Cursor::~Cursor()
	{
		glfwDestroyCursor(m_cursor);
	}

	Mouse::Cursor& Mouse::Cursor::operator=(Cursor&& cursor) noexcept
	{
		m_cursor = cursor.m_cursor;
		cursor.m_cursor = nullptr;
		
		return *this;
	}

	void Mouse::Cursor::setActive(Window& window)
	{
		glfwSetCursor(static_cast<GLFWwindow*>(window.getPlatformWindow()), m_cursor);
	}

	void Mouse::Cursor::setStandard(Window& window)
	{
		if(m_cursor != nullptr)
			glfwDestroyCursor(m_cursor);

		m_cursor = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
	}

	void Mouse::Cursor::reset(Window& window)
	{
		glfwSetCursor(static_cast<GLFWwindow*>(window.getPlatformWindow()), nullptr);
	}

	Mouse::Button Mouse::getButton(int button)
	{
		switch (button)
		{
		case GLFW_MOUSE_BUTTON_1: return Mouse::Button::One; break;
		case GLFW_MOUSE_BUTTON_2: return Mouse::Button::Two; break;
		case GLFW_MOUSE_BUTTON_3: return Mouse::Button::Three; break;
		case GLFW_MOUSE_BUTTON_4: return Mouse::Button::Four; break;
		case GLFW_MOUSE_BUTTON_5: return Mouse::Button::Five; break;
		case GLFW_MOUSE_BUTTON_6: return Mouse::Button::Six; break;
		case GLFW_MOUSE_BUTTON_7: return Mouse::Button::Seven; break;
		case GLFW_MOUSE_BUTTON_8: return Mouse::Button::Eight; break;
		default: return Mouse::Button::None; break;
		}
	}

	int Mouse::getPlatformButton(Mouse::Button button)
	{
		switch (button)
		{
		case Mouse::Button::One: return GLFW_MOUSE_BUTTON_1; break;
		case Mouse::Button::Two: return GLFW_MOUSE_BUTTON_2; break;
		case Mouse::Button::Three: return GLFW_MOUSE_BUTTON_3; break;
		case Mouse::Button::Four: return GLFW_MOUSE_BUTTON_4; break;
		case Mouse::Button::Five: return GLFW_MOUSE_BUTTON_5; break;
		case Mouse::Button::Six: return GLFW_MOUSE_BUTTON_6; break;
		case Mouse::Button::Seven: return GLFW_MOUSE_BUTTON_7; break;
		case Mouse::Button::Eight: return GLFW_MOUSE_BUTTON_8; break;
		default: return GLFW_KEY_UNKNOWN; break;
		}
	}

	bool Mouse::isKeyPressed(Window& window, Mouse::Button button)
	{
		return glfwGetMouseButton(static_cast<GLFWwindow*>(window.getPlatformWindow()), getPlatformButton(button)) == GLFW_PRESS;
	}

	bool Mouse::isKeyReleased(Window& window, Mouse::Button button)
	{
		return glfwGetMouseButton(static_cast<GLFWwindow*>(window.getPlatformWindow()), getPlatformButton(button)) == GLFW_RELEASE;
	}

	void Mouse::setCursorMode(Window& window, CursorMode cursorMode)
	{
		switch (cursorMode)
		{
		case CursorMode::Normal: glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_CURSOR, GLFW_CURSOR_NORMAL); break;
		case CursorMode::Hidden: glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_CURSOR, GLFW_CURSOR_HIDDEN); break;
		case CursorMode::Disabled: glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_CURSOR, GLFW_CURSOR_DISABLED); break;
		}
	}

	void Mouse::enableRawMotion(Window& window, bool enable)
	{
		if(glfwRawMouseMotionSupported())
			glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_RAW_MOUSE_MOTION, enable);
	}

	void Mouse::enableStickyKeys(Window& window, bool enable)
	{
		glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_STICKY_KEYS, enable);
	}

	void Mouse::enableStickyMouseButtons(Window& window, bool enable)
	{
		glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_STICKY_MOUSE_BUTTONS, enable);
	}

	void Mouse::lockKeyModifiers(Window& window, bool lock)
	{
		glfwSetInputMode(static_cast<GLFWwindow*>(window.getPlatformWindow()), GLFW_LOCK_KEY_MODS, lock);
	}

	Vector2 Mouse::getPosition(Window& window)
	{
		double xpos = 0.0, ypos = 0.0;
		glfwGetCursorPos(static_cast<GLFWwindow*>(window.getPlatformWindow()), &xpos, &ypos);

		return Vector2{ static_cast<int>(xpos), static_cast<int>(ypos) };
	}
}
