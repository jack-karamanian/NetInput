#pragma once
#include <memory>
#include "DeviceType.h"

namespace ni {
	class EventHandler;
}

std::shared_ptr<ni::EventHandler> GetOSEventHandler(ni::DeviceType devices);
