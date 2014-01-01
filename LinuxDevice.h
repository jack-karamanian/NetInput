#pragma once
#include <stdint.h>
#include <linux/uinput.h>
#include "FileDesc.h"

namespace ni {
	struct LinuxDevice {
		uinput_user_dev _device;
		FileDesc		_device_fd;

		LinuxDevice();
		bool isValid() const;
	};

	LinuxDevice linux_device_create(const char *name);
	void	    linux_device_destroy(LinuxDevice device);
}