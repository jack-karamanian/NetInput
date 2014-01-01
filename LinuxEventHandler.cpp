#include <linux/input.h>
#include <unistd.h>
#include <cstring>
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
	sendEvent(m_mouse, EV_REL, REL_X, event.deltaX);
	sendEvent(m_mouse, EV_REL, REL_Y, event.deltaY);
	sendEvent(m_mouse, EV_REL, REL_WHEEL, event.deltaWheel);
	sendEvent(m_mouse, EV_KEY, BTN_LEFT, event.leftButtonDown);
	sendEvent(m_mouse, EV_KEY, BTN_RIGHT, event.rightButtonDown);
	sendEvent(m_mouse, EV_KEY, BTN_MIDDLE, event.middleButtonDown);
	sendEvent(m_mouse, EV_SYN, 0, 0);
}

void LinuxEventHandler::handleKeyboardEvent(const KeyboardEvent& event) {

}

void LinuxEventHandler::handleGamepadEvent(const GamepadEvent& event) {

}

void LinuxEventHandler::sendEvent(const LinuxDevice& device, int type, int code, int value) {
	input_event ev;
	memset(&ev, 0, sizeof(input_event));
	ev.type = type;
	ev.code = code;
	ev.value = value;

	write(device._device_fd, &ev, sizeof(input_event));
}