#pragma once

#include "Windove/Export.hpp"

#include <bitset>

namespace dove
{
	class Modifiers
	{
	public:
		enum InputModifier
		{
			Shift = 0,
			Control,
			Alt,
			Super,
			CapsLock,
			NumLock
		};

		using InputModifiers = std::bitset<6>;

		WINDOVE_API static InputModifiers getInputModifiers(int inputModifiers);
	};
}