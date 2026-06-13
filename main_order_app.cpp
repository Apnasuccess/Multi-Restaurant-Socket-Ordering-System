#include <iostream>
#include <sstream>
#include <vector>
<<<<<<< HEAD
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

=======

#include "SocketClient.h"

>>>>>>> b9d99cd314b9bade61b840d4e6d0a7f191744a74
int main()
{
    SocketClient client;

    std::vector<ResponsePacket> history;

    int requestId = 100;

<<<<<<< HEAD
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
=======
    while(true)
    {
        std::string line;
        std::cout << "\nEnter command: ";
        std::getline(std::cin, line);

        if(line == "exit")
            break;

        if(line == "status")
        {
            std::cout << "\nOrder Summary:\n";

            for(auto &res : history)
            {
                std::cout
                    << res.serverName
                    << " -> "
                    << res.status
                    << ", ETA "
                    << res.estimatedTime
                    << " min\n";
>>>>>>> b9d99cd314b9bade61b840d4e6d0a7f191744a74
            }

            continue;
        }

        std::stringstream ss(line);

<<<<<<< HEAD
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
=======
        std::string cmd, item, notes;
        int quantity;

        ss >> cmd >> item >> quantity;

        std::getline(ss, notes);

        // clean notes
        if(notes.size() > 0 && notes[0] == ' ')
            notes = notes.substr(1);

        if(quantity <= 0)
        {
            std::cout
                << "ERROR: quantity must be greater than 0\n";
>>>>>>> b9d99cd314b9bade61b840d4e6d0a7f191744a74
            continue;
        }

        RequestPacket req;
<<<<<<< HEAD
        req.requestId = requestId++;
        req.customerName = "Customer";
=======

        req.requestId = requestId++;
        req.customerName = "Amit";
>>>>>>> b9d99cd314b9bade61b840d4e6d0a7f191744a74
        req.item = item;
        req.quantity = quantity;
        req.notes = notes;

        int port = 0;
<<<<<<< HEAD
        if(item == "pizza") port = 5001;
        else if(item == "burger") port = 5002;
        else port = 5003; // drinks

        ResponsePacket res = client.sendRequestToServer("127.0.0.1", port, req);

        history.push_back(res);

        std::cout << "Response: " << res.message << ", ETA " << res.estimatedTime << " min\n";
=======

        if(item == "pizza")
            port = 5001;
        else if(item == "burger")
            port = 5002;
        else
            port = 5003;

        ResponsePacket res =
            client.sendRequestToServer(
                "127.0.0.1",
                port,
                req
            );

        history.push_back(res);

        std::cout
            << "Response: "
            << res.message
            << ", ETA "
            << res.estimatedTime
            << " min\n";
>>>>>>> b9d99cd314b9bade61b840d4e6d0a7f191744a74
    }

    return 0;
}
