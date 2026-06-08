#include <iostream>
#include <sstream>
#include <vector>

#include "SocketClient.h"

int main()
{
    SocketClient client;

    std::vector<ResponsePacket> history;

    int requestId = 100;

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
            }

            continue;
        }

        std::stringstream ss(line);

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
            continue;
        }

        RequestPacket req;

        req.requestId = requestId++;
        req.customerName = "Amit";
        req.item = item;
        req.quantity = quantity;
        req.notes = notes;

        int port = 0;

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
    }

    return 0;
}