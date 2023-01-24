#include "data-listener/data-listener.h"
#include "games/games.h"
#include "games/packet-wrapper.h"
#include "debug/debug.h"
#include <stdio.h>
#include <queue>
#include <thread>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
  //Choix du jeu
  Games selectedGame(game::F1_2020);
  //Création de la queue de debug
  queue<PacketWrapper> debugQueue;
  //On initialise le listener
  DataListener listener("20777", &selectedGame);
  if (listener.initSocket() == -1) {
    //ERROR
    return -1;
  }
  //Création du thread de debug
  DebugThread debugObj{};
  printf("Addresse du debugObj (main thread) : %p\n", &debugObj);
  thread debugT{&DebugThread::start, &debugObj, &debugQueue};
  //Réception des paquets
  listener.listen(&debugQueue);
  printf("J'attends 6 secondes !");
  sleep(6);
  debugObj.stop();
  debugT.join();
  printf("C'est la fin...\n");
}
