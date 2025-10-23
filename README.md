# Windove

Windove is a C++ library that encapsulates the management of a **window**. It provides an **event handler** that can be inherited from to receive events.
The window can be **customized** with options and manipulated at runtime.
The event handler acts as an observer that can register objects to notify. The events are related to the window.
Multiple windows can be created, each producing their own events. The library has to be initialized before opening a window, and closed when no longer needed with the `Window::initialize` and `Window::terminate` static methods.
The library uses **GLFW** to manage the windows.

## Usage

### Window

Here is an example that opens and manages a window :
```c++
#include <Windove/Window.hpp>
#include <iostream>

int main()
{
	std::cout << "Windove" << std::endl;

	dove::Window::initialize(); // Call this method before opening a window
	
	dove::WindowSettings windowSettings;
	
	windowSettings.openGLVersionMajor = 4;
	windowSettings.openGLVersionMinor = 0;
	windowSettings.samples = 0;
	windowSettings.x = 150;
	windowSettings.y = 100;
	windowSettings.transparentFramebuffer = false;
	windowSettings.floating = false;

	dove::Window window("Window", 1280, 720, windowSettings);
	if(!window.isOpen())
		std::cerr << "Failed to open window" << std::endl;

	while (window.isOpen())
	{
		window.fetchEvents();
		
		// Physics and rendering here...
		
		window.display();
	}

	dove::Window::terminate(); // Call this method when the windows are no longer used

	std::cout << "Press enter to exit..." << std::endl;
	std::cin.get();

	return 0;
}
```

### Events

Here is an example of a class that receives events from a window :
```c++
#include <Windove/EventHandler.hpp>
#include <Windove/Window.hpp>
#include <iostream>

class EventReceiver : public dove::EventHandler
{
public:
	void onKeyPressed(dove::KeyEvent keyEvent) override
	{
		if(keyEvent.key == dove::Keyboard::Key::Escape)
			std::cout << "Escape key pressed" << std::endl;
	};
};

int main()
{
	// ...

	EventReceiver eventReceiver;
	window.addEventHandler(&eventReceiver);

	// ...
}
```

Any virtual method of the `EventHandler` class can be overriden to define behavior upon receiving the according event.

## Test application

**WindoveTest** is a test application that you can use to try the library with ease. It implements a few **use cases**.

## Setup

The project follows the [Nest](https://github.com/Brocolarbre/Nest/) structure.
To build the project :
- Open a terminal in the **root folder** of the project
- Run the following command :
  - Windows : `.\scripts\windows\set_workspace.bat`
  - Linux : `./scripts/linux/set_workspace.sh`
- Open the project workspace
- Build the project

### Static and dynamic linkage

Any project that uses the the static version of the library shoud define the `WINDOVE_STATIC` macro.
To manually export the library as a shared library, the project should define the `WINDOVE_EXPORT` macro.
Using the library as a static library requires to link the external dependencies of the library (as only a dynamic library or an executable can store static dependencies).
The dependencies are listed below, the library is guaranteed to work with the specified library versions. Replacing a library with another version may or may not work.

### External dependencies

**Windove** has the following external dependencies :
- GLFW (3.4)