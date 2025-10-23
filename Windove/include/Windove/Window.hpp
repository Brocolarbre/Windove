#pragma once

#include "EventDispatcher.hpp"

struct GLFWwindow;

namespace dove
{
	struct Vector2
	{
		int x;
		int y;
	};

	struct WindowSettings
	{
		bool resizable = true;
		bool visible = true;
		bool decorated = true;
		bool focused = true;
		bool autoMinimize = true;
		bool floating = false;
		bool maximized = false;
		bool transparentFramebuffer = false;
		int x = -1;
		int y = -1;
		unsigned int samples = 4;
		bool verticalSynchronization = true;
		bool useOpenGL = true;
		bool useOpenGLES = false;
		unsigned int openGLVersionMajor = 3;
		unsigned int openGLVersionMinor = 3;
		bool openGLCoreProfile = true;
		bool openGLForwardCompatibility = false;
	};

	class Window
	{
	private:
		GLFWwindow* m_window;
		EventDispatcher m_eventDispatcher;

		int m_x;
		int m_y;
		int m_width;
		int m_height;

		bool m_fullscreen;

		static bool m_initialized;

	public:
		WINDOVE_API Window();
		WINDOVE_API Window(const std::string& title, unsigned int width, unsigned int height, const WindowSettings& windowSettings = WindowSettings());
		WINDOVE_API Window(const Window& window) = delete;
		WINDOVE_API Window(Window&& window) noexcept;
		WINDOVE_API ~Window();

		WINDOVE_API Window& operator=(const Window& window) = delete;
		WINDOVE_API Window& operator=(Window&& window) noexcept;

		WINDOVE_API static bool initialize();
		WINDOVE_API static void terminate();

		WINDOVE_API const std::list<EventHandler*>& getEventHandlers() const;
		WINDOVE_API void clearEventHandlers();
		WINDOVE_API void addEventHandler(EventHandler& eventHandler);
		WINDOVE_API void removeEventHandler(EventHandler& eventHandler);

		WINDOVE_API bool isOpen() const;
		WINDOVE_API bool isFullscreen() const;
		WINDOVE_API std::string getTitle() const;
		WINDOVE_API Vector2 getPosition() const;
		WINDOVE_API Vector2 getSize() const;
		WINDOVE_API Vector2 getFramebufferSize() const;

		WINDOVE_API bool open(const std::string& title, unsigned int width, unsigned int height, const WindowSettings& windowSettings = WindowSettings());
		WINDOVE_API void close();
		WINDOVE_API void minimize();
		WINDOVE_API void maximize();
		WINDOVE_API void restore();
		WINDOVE_API void setTitle(const std::string& title);
		WINDOVE_API void setPosition(unsigned int x, unsigned int y);
		WINDOVE_API void setSize(unsigned int width, unsigned int height);
		WINDOVE_API void setSizeLimits(unsigned int minWidth, unsigned int maxWidth, unsigned int minHeight, unsigned int maxHeight);
		WINDOVE_API void setFullscreen(bool fullscreen);
		WINDOVE_API void setIcon(unsigned int width, unsigned int height, unsigned char* data);
		WINDOVE_API void requestAttention();
		WINDOVE_API void fetchEvents();
		WINDOVE_API void fetchEventsWait();
		WINDOVE_API void fetchEventsWaitTimeout(double timeout);
		WINDOVE_API void emitEmptyEvent();
		WINDOVE_API void display() const;
		WINDOVE_API void captureContext() const;
		WINDOVE_API void releaseContext() const;
		WINDOVE_API void* getPlatformWindow() const;
	};
}