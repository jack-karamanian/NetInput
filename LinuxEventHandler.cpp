#include "MouseEvent.h"
#include "LinuxEventHandler.h"

using namespace ni;

// TODO: Implement keyboard and gamepad

LinuxEventHandler::LinuxEventHandler(DeviceType devices) {
	if(devices & DeviceType::Mouse) {
		m_mouse = linux_mouse_create("netinput-vmouse");
	}
}

LinuxEventHandler::~LinuxEventHandler() {
	linux_device_destroy(m_mouse);
	linux_device_destroy(m_keyboard);
	linux_device_destroy(m_gamepad);
}

void LinuxEventHandler::handleMouseEvent(const MouseEvent& event) {

}

void LinuxEventHandler::handleKeyboardEvent(const KeyboardEvent& event) {

}

void LinuxEventHandler::handleGamepadEvent(const GamepadEvent& event) {

}