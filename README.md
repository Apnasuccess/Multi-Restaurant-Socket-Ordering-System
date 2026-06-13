# Multi Restaurant Socket Ordering System

## Overview

A C++ socket-based food ordering system where a client application sends requests to multiple restaurant servers and receives responses.

## Architecture

User
↓
main_order_app
↓
SocketClient
↓
TCP Network
↓
SocketServer
↓
RestaurantHandler
↓
ResponsePacket

## Servers

pizza_server -> Port 5001

burger_server -> Port 5002

drinks_server -> Port 5003

## Request Packet

requestId|customerName|item|quantity|notes

Example:

101|Amit|pizza|2|extra cheese

## Response Packet

requestId|serverName|status|message|estimatedTime

Example:

101|pizza_server|SUCCESS|Order accepted|15

## Build

make

## Run

Terminal 1:

./pizza_server

Terminal 2:

./burger_server

Terminal 3:

./drinks_server

Terminal 4:

./main_order_app

## Features

* Socket Communication
* Request Serialization
* Response Serialization
* Multi Server Routing
* Error Handling
* Order Summary

## Test Cases

See tests/test_cases.md

## Future Improvements

* GUI
* Database Storage
* Authentication
* Docker Deployment
* REST API
# Multi-Restaurant Socket Ordering System

## Overview

This project is a C++ TCP socket-based client-server application that simulates a food ordering system.

A central application (`main_order_app`) accepts customer orders and communicates with multiple restaurant servers using TCP sockets.

The system demonstrates:

* TCP Socket Programming
* Client-Server Architecture
* Packet Serialization and Deserialization
* Multi-Process Communication
* Object-Oriented Design
* Build Automation using Makefile

---

## Architecture

```text
                    +------------------+
                    |  main_order_app  |
                    +------------------+
                              |
                              |
                       SocketClient
                              |
                     TCP Socket Network
                              |
        ------------------------------------------------
        |                      |                       |
        |                      |                       |
+---------------+    +---------------+    +---------------+
| pizza_server  |    | burger_server |    | drinks_server |
+---------------+    +---------------+    +---------------+
        |                      |                       |
        +----------------------------------------------+
                              |
                        SocketServer
                              |
                     RestaurantHandler
```

---

## Project Structure

```text
Makefile

PacketCodec.cpp
PacketCodec.h

RestaurantHandler.cpp
RestaurantHandler.h

SocketClient.cpp
SocketClient.h

SocketServer.cpp
SocketServer.h

pizza_server.cpp
burger_server.cpp
drinks_server.cpp

main_order_app.cpp

README.md
```

---

## Server Configuration

| Server        | Port |
| ------------- | ---- |
| pizza_server  | 5001 |
| burger_server | 5002 |
| drinks_server | 5003 |

---

## Request Packet Format

```text
requestId|customerName|item|quantity|notes
```

Example:

```text
101|Amit|pizza|2|extra cheese
```

---

## Response Packet Format

```text
requestId|serverName|status|message|estimatedTime
```

Example:

```text
101|pizza_server|SUCCESS|Order accepted|15
```

---

## Restaurant Rules

### Pizza Server

* Available Item: pizza
* Maximum Quantity: 5
* Estimated Time: 15 minutes

### Burger Server

* Available Item: burger
* Maximum Quantity: 3
* Estimated Time: 10 minutes

### Drinks Server

Available Items:

* coke
* coffee
* juice

Maximum Quantity:

* 10

Estimated Time:

* 3 minutes

---

## Supported Commands

```text
order pizza 2 extra_cheese
order burger 1 no_onion
order coke 3 cold

status
exit
```

---

## Requirements

### Ubuntu / WSL

Install required tools:

```bash
sudo apt update
sudo apt install build-essential make -y
```

---

## Build Instructions

Build all applications:

```bash
make
```

Clean generated files:

```bash
make clean
```

---

## Running the Project

### Terminal 1

```bash
./pizza_server
```

Expected:

```text
[SERVER] Running on port 5001
```

---

### Terminal 2

```bash
./burger_server
```

Expected:

```text
[SERVER] Running on port 5002
```

---

### Terminal 3

```bash
./drinks_server
```

Expected:

```text
[SERVER] Running on port 5003
```

---

### Terminal 4

```bash
./main_order_app
```

Expected:

```text
Enter command:
```

---

## Example Usage

### Pizza Order

Input:

```text
order pizza 2 extra_cheese
```

Output:

```text
Response: Order accepted, ETA 15 min
```

---

### Burger Order

Input:

```text
order burger 1 no_onion
```

Output:

```text
Response: Order accepted, ETA 10 min
```

---

### Drink Order

Input:

```text
order coke 3 cold
```

Output:

```text
Response: Order accepted, ETA 3 min
```

---

## Status Command

Input:

```text
status
```

Example Output:

```text
Order Summary

pizza_server  -> SUCCESS, ETA 15 min
burger_server -> SUCCESS, ETA 10 min
drinks_server -> SUCCESS, ETA 3 min
```

---

## Error Handling

Implemented validations:

### Invalid Quantity

Input:

```text
order pizza 0 extra_cheese
```

Output:

```text
ERROR: quantity must be greater than 0
```

### Invalid Item

Output:

```text
ERROR: Invalid item
```

### Connection Failure

Output:

```text
[APP] ERROR: Could not connect to server
```

---

## Concepts Demonstrated

* TCP Socket Programming
* Client-Server Communication
* Request-Response Protocol
* Serialization / Deserialization
* Multi-Server Architecture
* Object-Oriented Programming (OOP)
* Build Automation with Makefile

---

## Future Improvements

* Multi-threaded servers
* Timeout handling
* Retry mechanism
* JSON-based packets
* Concurrent client support
* Logging system

## Tests

Run unit tests (simple PacketCodec test):

```bash
make test
```

## Quick start (WSL)

1. Open WSL or Linux shell.
2. Run `make`.
3. Start three servers in separate terminals: `./pizza_server`, `./burger_server`, `./drinks_server`.
4. Run `./main_order_app` and use `order` commands.

---

## Author

Rahul

C++ Socket Programming Practice Project
