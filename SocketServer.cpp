#include "SocketServer.h"

#include <iostream>
#include <cstring>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "PacketCodec.h"
#include "RestaurantHandler.h"

void SocketServer::start(int port)
{
    // Step 1: create socket
    int serverSock =
        socket(AF_INET, SOCK_STREAM, 0);

    if(serverSock < 0)
    {
        std::cout << "Socket creation failed\n";
        return;
    }

    // Step 2: bind address
    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    bind(serverSock,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr));

    // Step 3: listen
    listen(serverSock, 5);

    std::cout
        << "[SERVER] Running on port "
        << port << std::endl;

    while(true)
    {
        // Step 4: accept client
        int clientSock =
            accept(serverSock, nullptr, nullptr);

        std::cout << "[SERVER] Client connected\n";

        // Step 5: receive request
        char buffer[1024] = {0};

        recv(clientSock,
            buffer,
            sizeof(buffer),
            0);

        std::string rawRequest(buffer);

        std::cout
            << "[SERVER] Received: "
            << rawRequest << std::endl;

        // Step 6: parse request
        RequestPacket req =
            PacketCodec::parseRequest(rawRequest);

        // Step 7: process request (business logic happens here)
        ResponsePacket res;

        if(port == 5001)
            res = RestaurantHandler::processPizzaOrder(req);
        else if(port == 5002)
            res = RestaurantHandler::processBurgerOrder(req);
        else
            res = RestaurantHandler::processDrinkOrder(req);

        // Step 8: serialize response
        std::string responseStr =
            PacketCodec::serializeResponse(res);

        // Step 9: send response
        send(clientSock,
            responseStr.c_str(),
            responseStr.size(),
            0);

        std::cout << "[SERVER] Response sent\n";

        // Step 10: close client
        close(clientSock);
    }

    close(serverSock);
}