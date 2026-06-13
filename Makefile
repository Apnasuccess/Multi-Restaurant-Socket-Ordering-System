CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main_order_app pizza_server burger_server drinks_server PacketCodec_test

main_order_app: main_order_app.cpp SocketClient.cpp PacketCodec.cpp
	$(CXX) $(CXXFLAGS) -o main_order_app main_order_app.cpp SocketClient.cpp PacketCodec.cpp

pizza_server: pizza_server.cpp SocketServer.cpp RestaurantHandler.cpp PacketCodec.cpp
	$(CXX) $(CXXFLAGS) -o pizza_server pizza_server.cpp SocketServer.cpp RestaurantHandler.cpp PacketCodec.cpp

burger_server: burger_server.cpp SocketServer.cpp RestaurantHandler.cpp PacketCodec.cpp
	$(CXX) $(CXXFLAGS) -o burger_server burger_server.cpp SocketServer.cpp RestaurantHandler.cpp PacketCodec.cpp

drinks_server: drinks_server.cpp SocketServer.cpp RestaurantHandler.cpp PacketCodec.cpp
	$(CXX) $(CXXFLAGS) -o drinks_server drinks_server.cpp SocketServer.cpp RestaurantHandler.cpp PacketCodec.cpp

PacketCodec_test: PacketCodec_test.cpp PacketCodec.cpp
	$(CXX) $(CXXFLAGS) -o PacketCodec_test PacketCodec_test.cpp PacketCodec.cpp

test: PacketCodec_test
	./PacketCodec_test

clean:
	rm -f main_order_app pizza_server burger_server drinks_server PacketCodec_test
