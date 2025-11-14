#include "Windove/Input/Modifiers.hpp"

#include <GLFW/glfw3.h>

namespace dove
{
	Modifiers::InputModifiers Modifiers::getInputModifiers(int inputModifiers)
	{
		InputModifiers modifiers;

		if (inputModifiers & GLFW_MOD_SHIFT) modifiers.set(InputModifier::Shift);
		if (inputModifiers & GLFW_MOD_CONTROL) modifiers.set(InputModifier::Control);
		if (inputModifiers & GLFW_MOD_ALT) modifiers.set(InputModifier::Alt);
		if (inputModifiers & GLFW_MOD_SUPER) modifiers.set(InputModifier::Super);
		if (inputModifiers & GLFW_MOD_CAPS_LOCK) modifiers.set(InputModifier::CapsLock);
		if (inputModifiers & GLFW_MOD_NUM_LOCK) modifiers.set(InputModifier::NumLock);

		return modifiers;
	}
}