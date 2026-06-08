#include "PacketCodec.h"

#include <sstream>
#include <vector>
#include <stdexcept>

std::string PacketCodec::serializeRequest(
    const RequestPacket& req)
{
    return
        std::to_string(req.requestId) + "|" +
        req.customerName + "|" +
        req.item + "|" +
        std::to_string(req.quantity) + "|" +
        req.notes;
}

RequestPacket PacketCodec::parseRequest(
    const std::string& raw)
{
    std::stringstream ss(raw);

    std::vector<std::string> fields;

    std::string token;

    while(std::getline(ss, token, '|'))
    {
        fields.push_back(token);
    }

    if(fields.size() != 5)
    {
        throw std::runtime_error(
            "Malformed Request Packet");
    }

    RequestPacket req;

    req.requestId =
        std::stoi(fields[0]);

    req.customerName =
        fields[1];

    req.item =
        fields[2];

    req.quantity =
        std::stoi(fields[3]);

    req.notes =
        fields[4];

    return req;
}

std::string PacketCodec::serializeResponse(
    const ResponsePacket& res)
{
    return
        std::to_string(res.requestId) + "|" +
        res.serverName + "|" +
        res.status + "|" +
        res.message + "|" +
        std::to_string(res.estimatedTime);
}

ResponsePacket PacketCodec::parseResponse(
    const std::string& raw)
{
    std::stringstream ss(raw);

    std::vector<std::string> fields;

    std::string token;

    while(std::getline(ss, token, '|'))
    {
        fields.push_back(token);
    }

    if(fields.size() != 5)
    {
        throw std::runtime_error(
            "Malformed Response Packet");
    }

    ResponsePacket res;

    res.requestId =
        std::stoi(fields[0]);

    res.serverName =
        fields[1];

    res.status =
        fields[2];

    res.message =
        fields[3];

    res.estimatedTime =
        std::stoi(fields[4]);

    return res;
}