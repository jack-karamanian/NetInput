#include "Server.h"
int main(int argc, const char *argv[]) {
	ni::Server server(9000);
	server.run();
	return 0;
}