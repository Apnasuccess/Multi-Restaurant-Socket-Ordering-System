#pragma once

#include <string>
#include "PacketCodec.h"

class SocketClient
{
public:

    ResponsePacket sendRequestToServer(
        const std::string& host,
        int port,
        const RequestPacket& req
    );
};