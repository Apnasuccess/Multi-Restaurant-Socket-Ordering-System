#include "SocketServer.h"

int main()
{
    SocketServer server;
    server.start(5002);
    return 0;
}