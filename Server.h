#pragma once
#include "InputSystem.h"
#include "FileDesc.h"

namespace ni {
	class InputPacket;
	class Server {
	public:
		Server(DeviceType devices, short port);
		void run();
	private:
		void processPacket(const InputPacket& packet);
		FileDesc createSocket(short port);
		InputSystem m_inputSystem;
		FileDesc m_socket;
		bool m_running;
	};
}