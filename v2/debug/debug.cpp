#include "debug.h"
#include "../games/packet-type.h"
#include <queue>
#include <memory>
#include <stdio.h>
#include <unistd.h>
using namespace std;

void DebugThread::start(queue<unique_ptr<PacketType>> *q) {
  //On affiche tous les éléments
  while (!this->quit) {
    if (!q->empty()) {
      q->front()->debug();
      q->front().reset();
      q->pop();
    }
  }
}

void DebugThread::stop() {
  this->quit = true;
  printf("Vous voulez quitter... :(\n");
}
