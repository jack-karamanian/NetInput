#pragma once
#include "DeviceType.h"
#include "LinuxMouse.h"
#include "EventHandler.h"
namespace ni {
	class LinuxEventHandler : public EventHandler {
	public:
		LinuxEventHandler(DeviceType devices);
		~LinuxEventHandler();

		virtual void handleMouseEvent(const MouseEvent& event) override;
		virtual void handleKeyboardEvent(const KeyboardEvent& event) override;
		virtual void handleGamepadEvent(const GamepadEvent& event) override;
	private:
		void sendEvent(const LinuxDevice& device, int type, int code, int value);
		LinuxDevice m_mouse;
		LinuxDevice m_keyboard;
		LinuxDevice m_gamepad;
	};
}