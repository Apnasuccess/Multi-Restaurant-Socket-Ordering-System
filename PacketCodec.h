#pragma once

#include <string>

struct RequestPacket
{
    int requestId;
    std::string customerName;
    std::string item;
    int quantity;
    std::string notes;
};

struct ResponsePacket
{
    int requestId;
    std::string serverName;
    std::string status;
    std::string message;
    int estimatedTime;
};

class PacketCodec
{
public:

    static std::string serializeRequest(
        const RequestPacket& req);

    static RequestPacket parseRequest(
        const std::string& raw);

    static std::string serializeResponse(
        const ResponsePacket& res);

    static ResponsePacket parseResponse(
        const std::string& raw);
};