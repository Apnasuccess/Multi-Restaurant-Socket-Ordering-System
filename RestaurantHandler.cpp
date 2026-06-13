#include "RestaurantHandler.h"

ResponsePacket RestaurantHandler::processPizzaOrder(
    const RequestPacket& req)
{
    ResponsePacket res;

    res.requestId = req.requestId;
    res.serverName = "pizza_server";

    if(req.item != "pizza")
    {
        res.status = "ERROR";
        res.message = "Invalid item";
        res.estimatedTime = 0;

        return res;
    }

    if(req.quantity <= 0)
    {
        res.status = "ERROR";
        res.message =
            "Quantity must be greater than 0";

        res.estimatedTime = 0;

        return res;
    }

    if(req.quantity > 5)
    {
        res.status = "ERROR";
        res.message =
            "Maximum quantity is 5";

        res.estimatedTime = 0;

        return res;
    }

    res.status = "SUCCESS";
    res.message = "Order accepted";
    res.estimatedTime = 15;

    return res;
}

ResponsePacket RestaurantHandler::processBurgerOrder(
    const RequestPacket& req)
{
    ResponsePacket res;

    res.requestId = req.requestId;
    res.serverName = "burger_server";

    if(req.item != "burger")
    {
        res.status = "ERROR";
        res.message = "Invalid item";
        res.estimatedTime = 0;

        return res;
    }

    if(req.quantity <= 0)
    {
        res.status = "ERROR";
        res.message =
            "Quantity must be greater than 0";

        res.estimatedTime = 0;

        return res;
    }

    if(req.quantity > 3)
    {
        res.status = "ERROR";
        res.message =
            "Maximum quantity is 3";

        res.estimatedTime = 0;

        return res;
    }

    res.status = "SUCCESS";
    res.message = "Order accepted";
    res.estimatedTime = 10;

    return res;
}

ResponsePacket RestaurantHandler::processDrinkOrder(
    const RequestPacket& req)
{
    ResponsePacket res;

    res.requestId = req.requestId;
    res.serverName = "drinks_server";

    bool validItem =
        req.item == "coke" ||
        req.item == "coffee" ||
        req.item == "juice";

    if(!validItem)
    {
        res.status = "ERROR";
        res.message = "Invalid item";
        res.estimatedTime = 0;

        return res;
    }

    if(req.quantity <= 0)
    {
        res.status = "ERROR";
        res.message =
            "Quantity must be greater than 0";

        res.estimatedTime = 0;

        return res;
    }

    if(req.quantity > 10)
    {
        res.status = "ERROR";
        res.message =
            "Maximum quantity is 10";

        res.estimatedTime = 0;

        return res;
    }

    res.status = "SUCCESS";
    res.message = "Order accepted";
    res.estimatedTime = 3;

    return res;
}