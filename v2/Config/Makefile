CC = clang++
PARAMS = -std=c++20 -Wall
##################################################
#Games global
GAMES_SRC_PATH = ../games/
GAMES_OBJ_PATH = objects/games/
SRC_FILES_GAMES = $(wildcard $(GAMES_SRC_PATH)*.cpp)
HEADER_FILES_GAMES = $(wildcard $(GAMES_SRC_PATH)*.h)
OBJ_FILES_GAMES = $(SRC_FILES_GAMES:$(GAMES_SRC_PATH)%.cpp=$(GAMES_OBJ_PATH)%.o)
#recipes
$(GAMES_OBJ_PATH)%.o : $(GAMES_SRC_PATH)%.cpp $(GAMES_SRC_PATH)%.h
	$(CC) -o $@ -c $< $(PARAMS)
#Games global
##################################################


##################################################
#F12020 packets
F12020_SRC_PATH = ../games/F1-2020/packets-structures/
F12020_OBJ_PATH = objects/games/F1-2020/
SRC_FILES_F12020 = $(wildcard $(F12020_SRC_PATH)*.cpp)
HEADER_FILES_F12020 = $(wildcard $(F12020_SRC_PATH)*.h)
OBJ_FILES_F12020 = $(SRC_FILES_F12020:$(F12020_SRC_PATH)%.cpp=$(F12020_OBJ_PATH)%.o)
#recipes
$(F12020_OBJ_PATH)%.o : $(F12020_SRC_PATH)%.cpp $(F12020_SRC_PATH)%.h
	$(CC) -o $@ -c $< $(PARAMS)
#F12020 packets
##################################################


##################################################
#Debug
DEBUG_SRC_PATH = ../debug/
DEBUG_OBJ_PATH = objects/debug/
SRC_FILES_DEBUG = $(wildcard $(DEBUG_SRC_PATH)*.cpp)
HEADER_FILES_DEBUG = $(wildcard $(DEBUG_SRC_PATH)*.h)
OBJ_FILES_DEBUG = $(SRC_FILES_DEBUG:$(DEBUG_SRC_PATH)%.cpp=$(DEBUG_OBJ_PATH)%.o)
#recipes
$(DEBUG_OBJ_PATH)%.o : $(DEBUG_SRC_PATH)%.cpp $(DEBUG_SRC_PATH)%.h
	$(CC) -o $@ -c $< $(PARAMS)
#Debug
##################################################


##################################################
#Data listener
DATA_LISTENER_SRC_PATH = ../data-listener/
DATA_LISTENER_OBJ_PATH = objects/data-listener/
SRC_FILES_DATA_LISTENER = $(wildcard $(DATA_LISTENER_SRC_PATH)*.cpp)
HEADER_FILES_DATA_LISTENER = $(wildcard $(DATA_LISTENER_SRC_PATH)*.h)
OBJ_FILES_DATA_LISTENER = $(SRC_FILES_DATA_LISTENER:$(DATA_LISTENER_SRC_PATH)%.cpp=$(DATA_LISTENER_OBJ_PATH)%.o)
#recipes
$(DATA_LISTENER_OBJ_PATH)%.o : $(DATA_LISTENER_SRC_PATH)%.cpp $(DATA_LISTENER_SRC_PATH)%.h
	$(CC) -o $@ -c $< $(PARAMS)
#Data listener
##################################################


build: $(OBJ_FILES_GAMES) $(OBJ_FILES_F12020) $(OBJ_FILES_DEBUG) $(OBJ_FILES_DATA_LISTENER) objects/main.o executable/F1GamesTelemetry

run: $(OBJ_FILES_GAMES) $(OBJ_FILES_F12020) $(OBJ_FILES_DEBUG) $(OBJ_FILES_DATA_LISTENER) objects/main.o executable/F1GamesTelemetry
	./executable/F1GamesTelemetry


executable/F1GamesTelemetry : $(OBJ_FILES_GAMES) $(OBJ_FILES_F12020) $(OBJ_FILES_DEBUG) $(OBJ_FILES_DATA_LISTENER) objects/main.o
	$(CC) -o $@ $^ $(PARAMS)

objects/main.o : ../main.cpp
	$(CC) -o $@ -c $< $(PARAMS)

.PHONY: test clear

test :
	$(CC) -o objects/tests/car-setup.o -c ../games/F1-2020/packets-structures/car-setup.cpp $(PARAMS)
	$(CC) -o objects/tests/main.o -c ../main.cpp $(PARAMS)
	$(CC) -o objects/tests/games.o -c ../games/games.cpp $(PARAMS)
	$(CC) -o objects/tests/Test objects/tests/main.o objects/tests/games.o objects/tests/car-setup.o $(PARAMS)
	./objects/tests/Test


clear :
	rm -f $(GAMES_OBJ_PATH)*.o
	rm -f $(F12020_OBJ_PATH)*.o
	rm -f $(QUEUE_OBJ_PATH)*.o
	rm -f $(DEBUG_OBJ_PATH)*.o
	rm -f $(DATA_LISTENER_OBJ_PATH)*.o
	rm -f executable/F1GamesTelemetry
