#include "Windove/Window.hpp"
#include "Windove/Event/CursorEnteredEvent.hpp"
#include "Windove/Event/CursorLeftEvent.hpp"
#include "Windove/Event/DragAndDropEvent.hpp"
#include "Windove/Event/FramebufferResizedEvent.hpp"
#include "Windove/Event/KeyPressedEvent.hpp"
#include "Windove/Event/KeyReleasedEvent.hpp"
#include "Windove/Event/KeyRepeatedEvent.hpp"
#include "Windove/Event/MouseMovedEvent.hpp"
#include "Windove/Event/MousePressedEvent.hpp"
#include "Windove/Event/MouseReleasedEvent.hpp"
#include "Windove/Event/MouseScrolledEvent.hpp"
#include "Windove/Event/TextEnteredEvent.hpp"
#include "Windove/Event/WindowClosedEvent.hpp"
#include "Windove/Event/WindowFocusGainedEvent.hpp"
#include "Windove/Event/WindowFocusLostEvent.hpp"
#include "Windove/Event/WindowMaximizedEvent.hpp"
#include "Windove/Event/WindowMinimizedEvent.hpp"
#include "Windove/Event/WindowMovedEvent.hpp"
#include "Windove/Event/WindowResizedEvent.hpp"
#include "Windove/Event/WindowRestoredEvent.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	namespace
	{
		EventDispatcher& getEventDispatcher(GLFWwindow* window)
		{
			return *reinterpret_cast<EventDispatcher*>(glfwGetWindowUserPointer(window));
		}

		void character_callback(GLFWwindow* window, unsigned int codepoint)
		{
			getEventDispatcher(window).receiveEvent<TextEnteredEvent>(codepoint);
		}

		void cursor_enter_callback(GLFWwindow* window, int entered)
		{
			if(entered)
				getEventDispatcher(window).receiveEvent<CursorEnteredEvent>();
			else
				getEventDispatcher(window).receiveEvent<CursorLeftEvent>();
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			getEventDispatcher(window).receiveEvent<MouseMovedEvent>(static_cast<unsigned int>(xpos), static_cast<unsigned int>(ypos));
		}

		void drop_callback(GLFWwindow* window, int count, const char** paths)
		{
			std::vector<std::string> pathsStr(count);
			for (unsigned int i = 0; i < static_cast<unsigned int>(count); ++i)
				pathsStr[i] = paths[i];

			getEventDispatcher(window).receiveEvent<DragAndDropEvent>(pathsStr);
		}

		void framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			getEventDispatcher(window).receiveEvent<FramebufferResizedEvent>(static_cast<unsigned int>(width), static_cast<unsigned int>(height));
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Keyboard::Key keyCode = Keyboard::getKey(key);
			Modifiers::InputModifiers inputModifiers = Modifiers::getInputModifiers(mods);

			if (keyCode == Keyboard::Key::None)
				return;

			switch (action)
			{
			case GLFW_PRESS: getEventDispatcher(window).receiveEvent<KeyPressedEvent>(KeyEvent{ keyCode, inputModifiers }); break;
			case GLFW_RELEASE: getEventDispatcher(window).receiveEvent<KeyReleasedEvent>(KeyEvent{ keyCode, inputModifiers }); break;
			case GLFW_REPEAT: getEventDispatcher(window).receiveEvent<KeyRepeatedEvent>(KeyEvent{ keyCode, inputModifiers }); break;
			}
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Mouse::Button buttonCode = Mouse::getButton(button);
			Modifiers::InputModifiers inputModifiers = Modifiers::getInputModifiers(mods);

			if (buttonCode == Mouse::Button::None)
				return;

			double mouseX, mouseY;
			glfwGetCursorPos(window, &mouseX, &mouseY);

			switch (action)
			{
			case GLFW_PRESS: getEventDispatcher(window).receiveEvent<MousePressedEvent>(MouseEvent{ buttonCode, inputModifiers, static_cast<unsigned int>(mouseX), static_cast<unsigned int>(mouseY) }); break;
			case GLFW_RELEASE: getEventDispatcher(window).receiveEvent<MouseReleasedEvent>(MouseEvent{ buttonCode, inputModifiers, static_cast<unsigned int>(mouseX), static_cast<unsigned int>(mouseY) }); break;
			}
		}

		void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{
			getEventDispatcher(window).receiveEvent<MouseScrolledEvent>(static_cast<int>(xoffset), static_cast<int>(yoffset));
		}

		void window_close_callback(GLFWwindow* window)
		{
			getEventDispatcher(window).receiveEvent<WindowClosedEvent>();
		}

		void window_focus_callback(GLFWwindow* window, int focused)
		{
			if(focused)
				getEventDispatcher(window).receiveEvent<WindowFocusGainedEvent>();
			else
				getEventDispatcher(window).receiveEvent<WindowFocusLostEvent>();
		}

		void window_iconify_callback(GLFWwindow* window, int iconified)
		{
			if (iconified)
				getEventDispatcher(window).receiveEvent<WindowMinimizedEvent>();
			else
				getEventDispatcher(window).receiveEvent<WindowRestoredEvent>();
		}

		void window_maximize_callback(GLFWwindow* window, int maximized)
		{
			if (maximized)
				getEventDispatcher(window).receiveEvent<WindowMaximizedEvent>();
			else
				getEventDispatcher(window).receiveEvent<WindowRestoredEvent>();
		}

		void window_pos_callback(GLFWwindow* window, int xpos, int ypos)
		{
			getEventDispatcher(window).receiveEvent<WindowMovedEvent>(static_cast<unsigned int>(xpos), static_cast<unsigned int>(ypos));
		}

		void window_size_callback(GLFWwindow* window, int width, int height)
		{
			getEventDispatcher(window).receiveEvent<WindowResizedEvent>(static_cast<unsigned int>(width), static_cast<unsigned int>(height));
		}
	}

	bool Window::m_initialized = false;

	Window::Window() :
		m_window(nullptr),
		m_eventDispatcher(),
		m_x(0),
		m_y(0),
		m_width(0),
		m_height(0),
		m_fullscreen(false)
	{
		
	}

	Window::Window(const std::string& title, unsigned int width, unsigned int height, const WindowSettings& windowSettings) :
		m_window(nullptr),
		m_eventDispatcher(),
		m_x(0),
		m_y(0),
		m_width(width),
		m_height(height)
	{
		open(title, width, height, windowSettings);
	}

	Window::Window(Window&& window) noexcept :
		m_window(window.m_window),
		m_eventDispatcher(window.m_eventDispatcher),
		m_x(window.m_x),
		m_y(window.m_y),
		m_width(window.m_width),
		m_height(window.m_height),
		m_fullscreen(window.m_fullscreen)
	{
		window.m_window = nullptr;
		window.m_eventDispatcher = EventDispatcher();
		window.m_x = 0;
		window.m_y = 0;
		window.m_width = 0;
		window.m_height = 0;
		window.m_fullscreen = false;	
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	Window& Window::operator=(Window&& window) noexcept
	{
		m_window = window.m_window;
		m_eventDispatcher = std::move(window.m_eventDispatcher);
		m_x = window.m_x;
		m_y = window.m_y;
		m_width = window.m_width;
		m_height = m_height = window.m_height;
		m_fullscreen = window.m_fullscreen;

		window.m_window = nullptr;
		window.m_eventDispatcher = EventDispatcher();
		window.m_x = 0;
		window.m_y = 0;
		window.m_width = 0;
		window.m_height = 0;
		window.m_fullscreen = false;

		return *this;
	}

	bool Window::initialize()
	{
		if (m_initialized)
			return true;

		if (glfwInit() == GLFW_TRUE)
			m_initialized = true;

		return m_initialized;
	}

	void Window::terminate()
	{
		if (m_initialized)
		{
			glfwTerminate();
			m_initialized = false;
		}
	}

	const std::list<EventHandler*>& Window::getEventHandlers() const
	{
		return m_eventDispatcher.getEventHandlers();
	}

	void Window::clearEventHandlers()
	{
		m_eventDispatcher.clearEventHandlers();
	}

	void Window::addEventHandler(EventHandler& eventHandler)
	{
		m_eventDispatcher.addEventHandler(eventHandler);
	}

	void Window::removeEventHandler(EventHandler& eventHandler)
	{
		m_eventDispatcher.removeEventHandler(eventHandler);
	}

	bool Window::isOpen() const
	{
		return !glfwWindowShouldClose(m_window);
	}

	bool Window::isFullscreen() const
	{
		return m_fullscreen;
	}

	std::string Window::getTitle() const
	{
		return std::string(glfwGetWindowTitle(m_window));
	}

	Vector2 Window::getPosition() const
	{
		return { m_x, m_y };
	}

	Vector2 Window::getSize() const
	{
		return { m_width, m_height };
	}

	Vector2 Window::getFramebufferSize() const
	{
		int width, height;
		glfwGetFramebufferSize(m_window, &width, &height);

		return { width, height };
	}

	bool Window::open(const std::string& title, unsigned int width, unsigned int height, const WindowSettings& windowSettings)
	{
		if (!m_initialized)
			return false;

		if (m_window)
			glfwDestroyWindow(m_window);

		glfwWindowHint(GLFW_RESIZABLE, windowSettings.resizable ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_VISIBLE, windowSettings.visible ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_DECORATED, windowSettings.decorated ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_FOCUSED, windowSettings.focused ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_AUTO_ICONIFY, windowSettings.autoMinimize ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_FLOATING, windowSettings.floating ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_MAXIMIZED, windowSettings.maximized ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, windowSettings.transparentFramebuffer ? GLFW_TRUE : GLFW_FALSE);
		glfwWindowHint(GLFW_POSITION_X, windowSettings.x > -1 ? windowSettings.x : GLFW_ANY_POSITION);
		glfwWindowHint(GLFW_POSITION_Y, windowSettings.y > -1 ? windowSettings.y : GLFW_ANY_POSITION);
		glfwWindowHint(GLFW_SAMPLES, windowSettings.samples);

		if(windowSettings.useOpenGL)
			glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		else if(windowSettings.useOpenGLES)
			glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		else
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		if(windowSettings.useOpenGL || windowSettings.useOpenGLES)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, windowSettings.openGLVersionMajor);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, windowSettings.openGLVersionMinor);
			glfwWindowHint(GLFW_OPENGL_PROFILE, windowSettings.openGLCoreProfile ? GLFW_OPENGL_CORE_PROFILE : GLFW_OPENGL_COMPAT_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, windowSettings.openGLForwardCompatibility ? GLFW_TRUE : GLFW_FALSE);
		}

		m_window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title.c_str(), nullptr, nullptr);

		if (!m_window)
			return false;

		glfwSetWindowUserPointer(m_window, &m_eventDispatcher);

		glfwSetCharCallback(m_window, character_callback);
		glfwSetCursorEnterCallback(m_window, cursor_enter_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSetDropCallback(m_window, drop_callback);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		glfwSetScrollCallback(m_window, scroll_callback);
		glfwSetWindowCloseCallback(m_window, window_close_callback);
		glfwSetWindowFocusCallback(m_window, window_focus_callback);
		glfwSetWindowIconifyCallback(m_window, window_iconify_callback);
		glfwSetWindowMaximizeCallback(m_window, window_maximize_callback);
		glfwSetWindowPosCallback(m_window, window_pos_callback);
		glfwSetWindowSizeCallback(m_window, window_size_callback);

		captureContext();

		glfwSwapInterval(windowSettings.verticalSynchronization ? 1 : 0);

		return true;
	}

	void Window::close()
	{
		glfwSetWindowShouldClose(m_window, GLFW_TRUE);
	}

	void Window::minimize()
	{
		glfwIconifyWindow(m_window);
	}

	void Window::maximize()
	{
		glfwMaximizeWindow(m_window);
	}

	void Window::restore()
	{
		glfwRestoreWindow(m_window);
	}

	void Window::setTitle(const std::string& title)
	{
		glfwSetWindowTitle(m_window, title.c_str());
	}

	void Window::setPosition(unsigned int x, unsigned int y)
	{
		glfwSetWindowPos(m_window, x, y);
	}

	void Window::setSize(unsigned int width, unsigned int height)
	{
		glfwSetWindowSize(m_window, width, height);
	}

	void Window::setSizeLimits(unsigned int minWidth, unsigned int maxWidth, unsigned int minHeight, unsigned int maxHeight)
	{
		glfwSetWindowSizeLimits(m_window, minWidth, maxWidth, minHeight, maxHeight);
	}

	void Window::setFullscreen(bool fullscreen)
	{
		if (fullscreen)
		{
			glfwGetWindowPos(m_window, &m_x, &m_y);
			glfwGetWindowSize(m_window, &m_width, &m_height);

			GLFWmonitor* monitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);

			glfwSetWindowMonitor(m_window, monitor, 0, 0, mode->width, mode->height, 0);
		}
		else
		{
			glfwSetWindowMonitor(m_window, nullptr, m_x, m_y, m_width, m_height, 0);
		}

		m_fullscreen = fullscreen;
	}

	void Window::setIcon(unsigned int width, unsigned int height, unsigned char* data)
	{
		GLFWimage image{ static_cast<int>(width), static_cast<int>(height), data };
		glfwSetWindowIcon(m_window, 1, &image);
	}

	void Window::requestAttention()
	{
		glfwRequestWindowAttention(m_window);
	}

	void Window::fetchEvents()
	{
		glfwPollEvents();
		m_eventDispatcher.processEvents();
	}

	void Window::fetchEventsWait()
	{
		glfwWaitEvents();
		m_eventDispatcher.processEvents();
	}

	void Window::fetchEventsWaitTimeout(double timeout)
	{
		glfwWaitEventsTimeout(timeout);
		m_eventDispatcher.processEvents();
	}

	void Window::emitEmptyEvent()
	{
		glfwPostEmptyEvent();
	}

	void Window::display() const
	{
		glfwSwapBuffers(m_window);
	}

	void Window::captureContext() const
	{
		glfwMakeContextCurrent(m_window);
	}

	void Window::releaseContext() const
	{
		glfwMakeContextCurrent(nullptr);
	}

	void* Window::getPlatformWindow() const
	{
		return m_window;
	}
}
