executable/F1GamesTelemetry : objects/main.o objects/games.o objects/packet-manager.o objects/global-packet-F12020.o objects/data-listener.o objects/global-packet.o
	clang++ -o executable/F1GamesTelemetry objects/*.o -Wall -std=c++11

objects/main.o : ../main.cpp
	clang++ -o objects/main.o -c ../main.cpp -Wall -std=c++11

objects/games.o : ../games/games.cpp
	clang++ -o objects/games.o -c ../games/games.cpp -Wall -std=c++11

objects/global-packet-F12020.o : ../games/F1-2020/global-packet-F12020.cpp
	clang++ -o objects/global-packet-F12020.o -c ../games/F1-2020/global-packet-F12020.cpp -Wall -std=c++11

objects/packet-manager.o : ../games/packet-manager.cpp
	clang++ -o objects/packet-manager.o -c ../games/packet-manager.cpp -Wall -std=c++11

objects/data-listener.o : ../data-listener/data-listener.cpp
	clang++ -o objects/data-listener.o -c ../data-listener/data-listener.cpp -Wall -std=c++11

objects/global-packet.o : ../games/global-packet.cpp
	clang++ -o objects/global-packet.o -c ../games/global-packet.cpp -Wall -std=c++11

objects/f12020-packets.o : ../games/F1-2020/packets-structures/*.cpp
	clang++ -o objects/f12020-packets.o ../games/F1-2020/packets-structures/*.cpp
