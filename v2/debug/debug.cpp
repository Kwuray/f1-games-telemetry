#include "debug.h"
#include "../games/packet-type.h"
#include <stdio.h>

void DebugThread::start(queue<PacketType> *debugQueue) {
  //On affiche tous les éléments
  while (!this->quit) {
    printf("Dans la boucle :)\n")
    this_thread::sleep_for(second{1});
  }
  printf("Fin du thread...\n");
}

void DebugThread::stop() {
  this->quit = true;
  printf("Tu veux quitter ?\n");
}
