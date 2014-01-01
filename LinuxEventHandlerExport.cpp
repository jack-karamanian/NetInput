#include "LinuxEventHandler.h"
#include "OSEventHandlerExport.h"

std::shared_ptr<ni::EventHandler> GetOSEventHandler(ni::DeviceType devices) {
	return std::make_shared<ni::LinuxEventHandler>(devices);
}