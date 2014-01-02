#pragma once
#include <cstdint>

namespace ni {
	struct MouseEvent {
		int32_t deltaX;
		int32_t deltaY;
		int8_t deltaWheel;
		uint8_t leftButtonDown;
		uint8_t rightButtonDown;
		uint8_t middleButtonDown;
	};
	static_assert(sizeof(MouseEvent) == 12, "Improper mouse event size");
}