#include "SocketServer.h"

int main()
{
    SocketServer server;
    server.start(5001);
    return 0;
}