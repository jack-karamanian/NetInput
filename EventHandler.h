#pragma once

namespace ni {
	class MouseEvent;
	class KeyboardEvent;
	class GamepadEvent;

	class EventHandler {
	public:
		virtual void handleMouseEvent(const MouseEvent& event) = 0;
		virtual void handleKeyboardEvent(const KeyboardEvent& event) = 0;
		virtual void handleGamepadEvent(const GamepadEvent& event) = 0;
		virtual ~EventHandler() { }
	};
}