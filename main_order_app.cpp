#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "SocketClient.h"

void printHelp()
{
    std::cout << "Commands:\n";
    std::cout << "  order <item> <quantity> [notes]   - place an order\n";
    std::cout << "  status                            - show order history\n";
    std::cout << "  help                              - show this help\n";
    std::cout << "  exit                              - quit app\n";
    std::cout << "Available items: pizza, burger, coke, coffee, juice\n";
}

bool isValidItem(const std::string &item)
{
    static const std::vector<std::string> items = {
        "pizza", "burger", "coke", "coffee", "juice"
    };

    return std::find(items.begin(), items.end(), item) != items.end();
}

int main()
{
    SocketClient client;

    std::vector<ResponsePacket> history;

    int requestId = 100;

    std::cout << "Welcome to SimpleOrderCLI\nType 'help' for commands.\n";

    while(true)
    {
        std::string line;
        std::cout << "\n> ";
        std::getline(std::cin, line);

        if(line == "")
            continue;

        if(line == "exit")
            break;

        if(line == "help")
        {
            printHelp();
            continue;
        }

        if(line == "status")
        {
            std::cout << "\nOrder Summary:\n";
            std::cout << "Server           | Status  | ETA(min) | Message\n";
            std::cout << "------------------------------------------------\n";

            for(const auto &res : history)
            {
                std::cout
                    << res.serverName << std::string(16 - res.serverName.size(), ' ') << " | "
                    << res.status << std::string(7 - res.status.size(), ' ') << " | "
                    << res.estimatedTime << "       | "
                    << res.message << "\n";
            }

            continue;
        }

        std::stringstream ss(line);

        std::string cmd, item;
        int quantity = 0;
        ss >> cmd >> item >> quantity;

        std::string notes;
        std::getline(ss, notes);
        if(notes.size() > 0 && notes[0] == ' ')
            notes = notes.substr(1);

        if(cmd != "order")
        {
            std::cout << "Unknown command. Type 'help' for usage.\n";
            continue;
        }

        if(!isValidItem(item))
        {
            std::cout << "ERROR: invalid item '" << item << "'\n";
            continue;
        }

        if(quantity <= 0)
        {
            std::cout << "ERROR: quantity must be greater than 0\n";
            continue;
        }

        RequestPacket req;
        req.requestId = requestId++;
        req.customerName = "Customer";
        req.item = item;
        req.quantity = quantity;
        req.notes = notes;

        int port = 0;
        if(item == "pizza") port = 5001;
        else if(item == "burger") port = 5002;
        else port = 5003; // drinks

        ResponsePacket res = client.sendRequestToServer("127.0.0.1", port, req);

        history.push_back(res);

        std::cout << "Response: " << res.message << ", ETA " << res.estimatedTime << " min\n";
    }

    return 0;
}