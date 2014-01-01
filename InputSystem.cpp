#include "EventHandler.h"
#include "OSEventHandlerExport.h"
#include "MouseEvent.h"
#include "InputSystem.h"

using namespace ni;

InputSystem::InputSystem(DeviceType devices) {
	m_osImpl = GetOSEventHandler(devices);
}

void InputSystem::sendMouseEvent(const MouseEvent& event) {
	m_osImpl->handleMouseEvent(event);
}

void InputSystem::sendKeyboardEvent(const KeyboardEvent& event) {
	m_osImpl->handleKeyboardEvent(event);
}

void InputSystem::sendGamepadEvent(const GamepadEvent& event) {
	m_osImpl->handleGamepadEvent(event);
}