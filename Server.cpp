#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>
#include "InputPacket.h"
#include "Server.h"

using namespace ni;

Server::Server(short port) : m_socket(createSocket(port)), m_running(true) {

}

void Server::run() {
	InputPacket packet;
	while(m_running) {
		recvfrom(m_socket, &packet, sizeof(InputPacket), 0, nullptr, nullptr);
		if(packet.isValid()) {
			processPacket(packet);
		}
	}
}

void Server::processPacket(const InputPacket& packet) {
	if(packet.isSafe()) {
		
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