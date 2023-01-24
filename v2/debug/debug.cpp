#include "debug.h"
#include "../games/packet-type.h"
#include <stdio.h>
#include <unistd.h>

void DebugThread::start(queue<PacketWrapper> *q) {
  //On affiche tous les éléments
  while (!this->quit) {
    q.front().getPacket()->debug();
    delete q.front();
    q.pop();
  }
}

void DebugThread::stop() {
  this->quit = true;
}
