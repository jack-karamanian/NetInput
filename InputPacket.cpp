#include <cstring>
#include "InputPacket.h"

using namespace ni;

bool InputPacket::isValid() const {
	return magic == MAGIC;
}

bool InputPacket::isSafe() const {
	return length <= DATA_LENGTH && length >= 0;
}