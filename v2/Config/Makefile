Executable/F1GamesTelemetry : Objects/main.o Objects/games.o Objects/packet-manager.o Objects/global-packet-F12020.o Objects/data-listener.o
	clang -o Executable/F1GamesTelemetry Objects/main.o Objects/games.o Objects/packet-manager.o Objects/global-packet-F12020.o Objects/data-listener.o -Wall

Objects/main.o : ../main.cpp
	clang -o Objects/main.o -c ../main.cpp -Wall

Objects/games.o : ../games/games.cpp
	clang -o Objects/games.o -c ../games/games.cpp -Wall

Objects/packet-manager.o : ../games/packet-manager.cpp
	clang -o Objects/packet-manager.o -c ../games/packet-manager.cpp -Wall

Objects/global-packet-F12020.o : ../games/F1-2020/global-packet-F12020.cpp
	clang -o Objects/global-packet-F12020.o -c ../games/F1-2020/global-packet-F12020.cpp -Wall

Objects/data-listener.o : ../data-listener/data-listener.cpp
	clang -o Objects/data-listener.o -c ../data-listener/data-listener.cpp -Wall
