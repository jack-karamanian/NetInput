#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include "LinuxMouse.h"

using namespace ni;

LinuxDevice linux_mouse_create(const char *name) {
	LinuxDevice dev = linux_device_create(name);
	int fd = dev._device_fd;

	// Enable mouse buttons
	ioctl(fd, UI_SET_EVBIT, EV_KEY);
	ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
	ioctl(fd, UI_SET_KEYBIT, BTN_RIGHT);

	// Enable relative axies
	ioctl(fd, UI_SET_EVBIT, EV_REL);
	ioctl(fd, UI_SET_RELBIT, REL_X);
	ioctl(fd, UI_SET_RELBIT, REL_Y);

	write(fd, &dev._device, sizeof(dev._device));

	ioctl(fd, UI_DEV_CREATE);
	return dev;
}