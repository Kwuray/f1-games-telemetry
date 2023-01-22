#include "data-listener/data-listener.h"
#include "games/games.h"
#include "queues/packet-queue.h"
#include <stdio.h>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
  //Choix du jeu
  Games selectedGame(game::F1_2020);
  //Création de la queue de debug
  queue<PacketQueue> debugQueue;
  //On initialise le listener
  DataListener listener("20777", &selectedGame, &debugQueue);
  listener.initSocket();
  //Réception des paquets
  listener.listen();
  printf("C'est la fin...\n");
}
