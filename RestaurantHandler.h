#pragma once

#include "PacketCodec.h"

class RestaurantHandler
{
public:

    static ResponsePacket processPizzaOrder(
        const RequestPacket& req);

    static ResponsePacket processBurgerOrder(
        const RequestPacket& req);

    static ResponsePacket processDrinkOrder(
        const RequestPacket& req);
};