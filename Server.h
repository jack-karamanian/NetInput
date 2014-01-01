#pragma once
#include "FileDesc.h"

namespace ni {
	class InputPacket;
	class Server {
	public:
		Server(short port);
		void run();
	private:
		void processPacket(const InputPacket& packet);
		FileDesc createSocket(short port);
		FileDesc m_socket;
		bool m_running;
	};
}