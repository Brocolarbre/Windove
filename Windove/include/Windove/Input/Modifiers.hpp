#pragma once

#include "Windove/Export.hpp"

#include <bitset>

namespace dove
{
	class WINDOVE_API Modifiers
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

		static InputModifiers getInputModifiers(int inputModifiers);
	};
}