#pragma once
#include <cstdint>

namespace ni {
	enum DeviceType : uint16_t {
		Mouse = 0x01,
		Keyboard = 0x02,
		Gamepad = 0x04
	};
}