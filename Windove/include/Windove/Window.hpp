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

	class WINDOVE_API Window
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
		Window();
		Window(const std::string& title, unsigned int width, unsigned int height, const WindowSettings& windowSettings = WindowSettings());
		Window(const Window& window) = delete;
		Window(Window&& window) noexcept;
		~Window();

		Window& operator=(const Window& window) = delete;
		Window& operator=(Window&& window) noexcept;

		static bool initialize();
		static void terminate();
		static void* getProcAddress(const char* procname);

		const std::list<EventHandler*>& getEventHandlers() const;
		void clearEventHandlers();
		void addEventHandler(EventHandler& eventHandler);
		void removeEventHandler(EventHandler& eventHandler);

		bool isOpen() const;
		bool isFullscreen() const;
		std::string getTitle() const;
		Vector2 getPosition() const;
		Vector2 getSize() const;
		Vector2 getFramebufferSize() const;

		bool open(const std::string& title, unsigned int width, unsigned int height, const WindowSettings& windowSettings = WindowSettings());
		void close();
		void minimize();
		void maximize();
		void restore();
		void setTitle(const std::string& title);
		void setPosition(unsigned int x, unsigned int y);
		void setSize(unsigned int width, unsigned int height);
		void setSizeLimits(unsigned int minWidth, unsigned int maxWidth, unsigned int minHeight, unsigned int maxHeight);
		void setFullscreen(bool fullscreen);
		void setIcon(unsigned int width, unsigned int height, unsigned char* data);
		void requestAttention();
		void fetchEvents();
		void fetchEventsWait();
		void fetchEventsWaitTimeout(double timeout);
		void emitEmptyEvent();
		void display() const;
		void captureContext() const;
		void releaseContext() const;
		void* getPlatformWindow() const;
	};
}