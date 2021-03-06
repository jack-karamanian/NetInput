#pragma once
#include <memory>
#include "DeviceType.h"

namespace ni {
	class MouseEvent;
	class KeyboardEvent;
	class GamepadEvent;
	class EventHandler;

	class InputSystem {
	public:
		InputSystem(DeviceType devices);
		void sendMouseEvent(const MouseEvent& event);
		void sendKeyboardEvent(const KeyboardEvent& event);
		void sendGamepadEvent(const GamepadEvent& event);
	private:
		std::shared_ptr<EventHandler> m_osImpl;
	};
}