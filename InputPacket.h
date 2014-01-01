#pragma once
#include <cstdint>

namespace ni {
	struct InputPacket {
		constexpr static int MAGIC = 0xD00D;
		constexpr static int TYPE_LENGTH = 16;
		constexpr static int DATA_LENGTH = 128;

		uint16_t magic;
		char type[TYPE_LENGTH];
		uint16_t length;
		uint8_t data[DATA_LENGTH];

		bool isValid() const;
		bool isSafe() const;
	};
}