#include "data-listener/data-listener.h"
#include "games/games.h"
#include "games/packet-type.h"
#include "debug/debug.h"
#include <stdio.h>
#include <queue>
#include <thread>
using namespace std;

int main(int argc, char *argv[]) {
  //Choix du jeu
  Games selectedGame(game::F1_2020);
  //Création de la queue de debug
  queue<PacketType> debugQueue;
  //On initialise le listener
  //DataListener listener("20777", &selectedGame, &debugQueue);
  //if (listener.initSocket() == -1) {
    //ERROR
    //return -1;
  //}
  //Création du thread de deug
  DebugThread debugObj();
  thread debugT(debugObj.start, &debugQueue);
  //Réception des paquets
  //listener.listen();
  printf("J'attends 6 secondes !");
  this_thread::sleep_for(second{6})
  debugObj.stop();
  debugT.join();
  printf("C'est la fin...\n");
}
