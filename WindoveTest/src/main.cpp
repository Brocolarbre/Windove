#include <Windove/Window.hpp>
#include <iostream>

int main()
{
	std::cout << "Windove" << std::endl;

	dove::Window::initialize();
	
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
		window.display();
	}

	dove::Window::terminate();

	std::cout << "Press enter to exit..." << std::endl;
	std::cin.get();

	return 0;
}