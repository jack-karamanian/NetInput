#include "DeviceType.h"
#include "Server.h"
int main(int argc, const char *argv[]) {
	ni::Server server(ni::DeviceType::Mouse, 9000);
	server.run();
	return 0;
}