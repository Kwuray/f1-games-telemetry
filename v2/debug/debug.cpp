#include "debug.h"
#include "../games/packet-type.h"
#include <stdio.h>

void DebugThread::start(queue<PacketType> *debugQueue) {
  //On affiche tous les éléments
  while (!this->quit) {
    debugQueue->front().debug();
    debugQueue->pop();
  }
  printf("Fin du thread...\n");
}

void DebugThread::stop() {
  this->quit = true;
}
