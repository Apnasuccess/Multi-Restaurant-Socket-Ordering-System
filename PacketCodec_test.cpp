#include <iostream>
#include "PacketCodec.h"

int main()
{
    RequestPacket req;
    req.requestId = 1;
    req.customerName = "TestUser";
    req.item = "pizza";
    req.quantity = 2;
    req.notes = "extra cheese";

    std::string s = PacketCodec::serializeRequest(req);

    RequestPacket parsed = PacketCodec::parseRequest(s);

    if(parsed.requestId != req.requestId || parsed.item != req.item || parsed.notes != req.notes)
    {
        std::cout << "Request parse/serialize failed\n";
        return 1;
    }

    ResponsePacket res;
    res.requestId = 1;
    res.serverName = "pizza_server";
    res.status = "SUCCESS";
    res.message = "OK";
    res.estimatedTime = 15;

    std::string r = PacketCodec::serializeResponse(res);

    ResponsePacket parsedRes = PacketCodec::parseResponse(r);

    if(parsedRes.serverName != res.serverName || parsedRes.estimatedTime != res.estimatedTime)
    {
        std::cout << "Response parse/serialize failed\n";
        return 2;
    }

    std::cout << "PacketCodec tests passed\n";
    return 0;
}
