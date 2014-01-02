#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include "MouseEvent.h"
#include "InputPacket.h"
#include "Server.h"

using namespace ni;

Server::Server(DeviceType devices, short port) : m_inputSystem(devices),
												 m_socket(createSocket(port)),
												 m_running(true) 
{

}

void Server::run() {
	InputPacket packet;
	while(m_running) {
		ssize_t numBytes = recvfrom(m_socket, &packet, sizeof(InputPacket), 0, nullptr, nullptr);
		std::cerr << "Recieved " << numBytes << " bytes" << std::endl;
		if(packet.isValid()) {
			processPacket(packet);
		} else {
			std::cerr << "Packet not valid" << std::endl;
		}
	}
}

void Server::processPacket(const InputPacket& packet) {
	if(packet.isSafe()) {
		if(packet.type == DeviceType::Mouse && packet.length == sizeof(MouseEvent)) {
			std::cerr << "Mouse event recieved." << std::endl;
			const MouseEvent event = *reinterpret_cast<const MouseEvent*>(packet.data);
			m_inputSystem.sendMouseEvent(event);
		}
	} else {
		std::cerr << "Packet not safe!" << std::endl;
	}
}

FileDesc Server::createSocket(short port) {
	sockaddr_in address;
	FileDesc sock = socket(AF_INET, SOCK_DGRAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(port);

	bind(sock, (sockaddr *)&address, sizeof(address));
	return sock;
}