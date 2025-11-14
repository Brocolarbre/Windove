#include "Windove/Input/Controller.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	bool Controller::isConnected(Id controller)
	{
		return glfwJoystickPresent(getPlatformController(controller));
	}

	bool Controller::isGamepad(Id controller)
	{
		return glfwJoystickIsGamepad(getPlatformController(controller));
	}

	Controller::Id Controller::getController(int controller)
	{
		switch (controller)
		{
		case GLFW_JOYSTICK_1: return Id::Controller1; break;
		case GLFW_JOYSTICK_2: return Id::Controller2; break;
		case GLFW_JOYSTICK_3: return Id::Controller3; break;
		case GLFW_JOYSTICK_4: return Id::Controller4; break;
		case GLFW_JOYSTICK_5: return Id::Controller5; break;
		case GLFW_JOYSTICK_6: return Id::Controller6; break;
		case GLFW_JOYSTICK_7: return Id::Controller7; break;
		case GLFW_JOYSTICK_8: return Id::Controller8; break;
		case GLFW_JOYSTICK_9: return Id::Controller9; break;
		case GLFW_JOYSTICK_10: return Id::Controller10; break;
		case GLFW_JOYSTICK_11: return Id::Controller11; break;
		case GLFW_JOYSTICK_12: return Id::Controller12; break;
		case GLFW_JOYSTICK_13: return Id::Controller13; break;
		case GLFW_JOYSTICK_14: return Id::Controller14; break;
		case GLFW_JOYSTICK_15: return Id::Controller15; break;
		case GLFW_JOYSTICK_16: return Id::Controller16; break;
		default: return Id::None; break;
		}
	}

	int Controller::getPlatformController(Id controller)
	{
		switch (controller)
		{
		case  Id::Controller1: return GLFW_JOYSTICK_1; break;
		case Id::Controller2: return GLFW_JOYSTICK_2; break;
		case Id::Controller3: return GLFW_JOYSTICK_3; break;
		case Id::Controller4: return GLFW_JOYSTICK_4; break;
		case Id::Controller5: return GLFW_JOYSTICK_5; break;
		case Id::Controller6: return GLFW_JOYSTICK_6; break;
		case Id::Controller7: return GLFW_JOYSTICK_7; break;
		case Id::Controller8: return GLFW_JOYSTICK_8; break;
		case Id::Controller9: return GLFW_JOYSTICK_9; break;
		case Id::Controller10: return GLFW_JOYSTICK_10; break;
		case Id::Controller11: return GLFW_JOYSTICK_11; break;
		case Id::Controller12: return GLFW_JOYSTICK_12; break;
		case Id::Controller13: return GLFW_JOYSTICK_13; break;
		case Id::Controller14: return GLFW_JOYSTICK_14; break;
		case Id::Controller15: return GLFW_JOYSTICK_15; break;
		case Id::Controller16: return GLFW_JOYSTICK_16; break;
		default: return GLFW_KEY_UNKNOWN; break;
		}
	}

	std::string Controller::getName(Id controller)
	{
		return std::string(glfwGetJoystickName(getPlatformController(controller)));
	}

	std::string Controller::getGamepadName(Id controller)
	{
		return std::string(glfwGetGamepadName(getPlatformController(controller)));
	}

	std::vector<float> Controller::getJoysticks(Id controller)
	{
		int axesCount = 0;
		const float* axesData = glfwGetJoystickAxes(getPlatformController(controller), &axesCount);

		std::vector<float> axes;
		for (int i = 0; i < axesCount; ++i)
			axes.push_back(axesData[i]);

		return axes;
	}

	std::vector<bool> Controller::getButtons(Id controller)
	{
		int buttonsCount = 0;
		const unsigned char* buttonsData = glfwGetJoystickButtons(getPlatformController(controller), &buttonsCount);

		std::vector<bool> buttons;
		for (int i = 0; i < buttonsCount; ++i)
			buttons.push_back(buttonsData[i]);

		return buttons;
	}

	std::vector<Controller::Hat> Controller::getHats(Id controller)
	{
		int hatsCount = 0;
		const unsigned char* hatsData = glfwGetJoystickHats(getPlatformController(controller), &hatsCount);

		std::vector<Hat> hats;
		for (int i = 0; i < hatsCount; ++i)
		{
			switch (hatsData[i])
			{
			case GLFW_HAT_CENTERED: hats.push_back(Hat::Centered); break;
			case GLFW_HAT_UP: hats.push_back(Hat::Up); break;
			case GLFW_HAT_RIGHT: hats.push_back(Hat::Right); break;
			case GLFW_HAT_DOWN: hats.push_back(Hat::Down); break;
			case GLFW_HAT_LEFT: hats.push_back(Hat::Left); break;
			case GLFW_HAT_RIGHT_UP: hats.push_back(Hat::RightUp); break;
			case GLFW_HAT_RIGHT_DOWN: hats.push_back(Hat::RightDown); break;
			case GLFW_HAT_LEFT_UP: hats.push_back(Hat::LeftUp); break;
			case GLFW_HAT_LEFT_DOWN: hats.push_back(Hat::LeftDown); break;
			}
		}

		return hats;
	}

	Controller::GamepadState Controller::getGamepadState(Id controller)
	{
		GLFWgamepadstate gamepadStateData;
		glfwGetGamepadState(getPlatformController(controller), &gamepadStateData);

		GamepadState gamepadState;

		gamepadState.buttons.reserve(GLFW_GAMEPAD_BUTTON_LAST);
		gamepadState.joysticks.reserve(GLFW_GAMEPAD_AXIS_LAST);

		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_A]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_B]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_X]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_Y]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_LEFT_BUMPER]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_BACK]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_START]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_GUIDE]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_LEFT_THUMB]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_RIGHT_THUMB]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_DPAD_UP]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_DPAD_RIGHT]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_DPAD_DOWN]);
		gamepadState.buttons.push_back(gamepadStateData.buttons[GLFW_GAMEPAD_BUTTON_DPAD_LEFT]);

		gamepadState.joysticks.push_back(gamepadStateData.axes[GLFW_GAMEPAD_AXIS_LEFT_X]);
		gamepadState.joysticks.push_back(gamepadStateData.axes[GLFW_GAMEPAD_AXIS_LEFT_Y]);
		gamepadState.joysticks.push_back(gamepadStateData.axes[GLFW_GAMEPAD_AXIS_RIGHT_X]);
		gamepadState.joysticks.push_back(gamepadStateData.axes[GLFW_GAMEPAD_AXIS_RIGHT_Y]);
		gamepadState.joysticks.push_back(gamepadStateData.axes[GLFW_GAMEPAD_AXIS_LEFT_TRIGGER]);
		gamepadState.joysticks.push_back(gamepadStateData.axes[GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER]);

		return gamepadState;
	}

	void Controller::updateGamepadMappings(const std::string& mappings)
	{
		glfwUpdateGamepadMappings(mappings.c_str());
	}
}