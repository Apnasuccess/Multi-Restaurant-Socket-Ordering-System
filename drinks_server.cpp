#include "SocketServer.h"

int main()
{
    SocketServer server;
    server.start(5003);
    return 0;
}