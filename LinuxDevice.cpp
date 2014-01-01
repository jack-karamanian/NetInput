#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <linux/uinput.h>
#include "LinuxDevice.h"

namespace ni {

LinuxDevice::LinuxDevice() : _device({ 0 }), _device_fd(-1) {

}

bool LinuxDevice::isValid() const {
	return ((int)_device_fd) != -1;
}

LinuxDevice linux_device_create(const char *name) {
	LinuxDevice dev;
	memset(&dev, 0, sizeof(dev));
	dev._device_fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
	snprintf(dev._device.name, UINPUT_MAX_NAME_SIZE, name);

	dev._device.id.bustype = BUS_USB;
	dev._device.id.vendor  = 0x1234;
	dev._device.id.product = 0xbeef;
	dev._device.id.version = 1;
	return dev;
}

void linux_device_destroy(LinuxDevice device) {
	ioctl(device._device_fd, UI_DEV_DESTROY);
}

}
