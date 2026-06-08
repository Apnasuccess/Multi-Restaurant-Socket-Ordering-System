#include "SocketClient.h"

#include <iostream>
#include <cstring>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

ResponsePacket SocketClient::sendRequestToServer(
    const std::string& host,
    int port,
    const RequestPacket& req)
{
    // Step 1: convert request to string
    std::string requestStr =
        PacketCodec::serializeRequest(req);

    // Step 2: create socket
    int sock =
        socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0)
    {
        std::cout << "Socket creation failed\n";
        return {};
    }

    // Step 3: setup server address
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    inet_pton(
        AF_INET,
        host.c_str(),
        &serverAddr.sin_addr
    );

    // Step 4: connect
    if(connect(sock,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)) < 0)
    {
        std::cout
            << "[APP] ERROR: Could not connect\n";

        return {};
    }

    // Step 5: send request
    send(sock,
        requestStr.c_str(),
        requestStr.size(),
        0);

    std::cout << "[APP] Packet sent\n";

    // Step 6: receive response
    char buffer[1024] = {0};

    recv(sock,
        buffer,
        sizeof(buffer),
        0);

    std::string responseStr(buffer);

    // Step 7: close socket
    close(sock);

    // Step 8: parse response
    ResponsePacket res =
        PacketCodec::parseResponse(responseStr);

    return res;
}