#pragma once

#include "Windove/Export.hpp"

#include <string>
#include <vector>

namespace dove
{
	class WINDOVE_API Controller
	{
	public:
		enum class Id
		{
			None = -1,
			Controller1,
			Controller2,
			Controller3,
			Controller4,
			Controller5,
			Controller6,
			Controller7,
			Controller8,
			Controller9,
			Controller10,
			Controller11,
			Controller12,
			Controller13,
			Controller14,
			Controller15,
			Controller16
		};

		enum class Hat
		{
			Centered = 0,
			Up,
			Right,
			Down,
			Left,
			RightUp,
			RightDown,
			LeftUp,
			LeftDown
		};

		enum class Joystick
		{
			LeftX = 0,
			LeftY,
			RightX,
			RightY,
			LeftTrigger,
			RightTrigger
		};

		enum class Button
		{
			A = 0,
			B,
			X,
			Y,
			LeftBumber,
			RightBumber,
			Back,
			Start,
			Guide,
			LeftThumb,
			RightThumb,
			DPadUp,
			DPadRight,
			DPadDown,
			DPadLeft,
			Cross = A,
			Circle = B,
			Square = X,
			Triangle = Y
		};

		struct GamepadState
		{
			std::vector<bool> buttons;
			std::vector<float> joysticks;
		};

		static bool isConnected(Id controller);
		static bool isGamepad(Id controller);

		static Id getController(int controller);
		static int getPlatformController(Id controller);

		static std::string getName(Id controller);
		static std::string getGamepadName(Id controller);

		static std::vector<float> getJoysticks(Id controller);
		static std::vector<bool> getButtons(Id controller);
		static std::vector<Hat> getHats(Id controller);

		static GamepadState getGamepadState(Id controller);
		static void updateGamepadMappings(const std::string& mappings);
	};
}