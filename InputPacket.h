#pragma once
#include <cstdint>
#include "DeviceType.h"

namespace ni {
	struct InputPacket {
		constexpr static int MAGIC = 0xD00D;
		constexpr static int DATA_LENGTH = 32;

		uint16_t magic;
		DeviceType type;
		uint16_t length;
		uint8_t data[DATA_LENGTH];

		bool isValid() const;
		bool isSafe() const;
	};

	static_assert(sizeof(InputPacket) == 38, "Improper InputPacket size");
}