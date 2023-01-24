#include "packet-queue.h"

//constructor
PacketQueue::PacketQueue(char *rawPacket) {
  this->rawPacket = rawPacket;
}

//destructor
PacketQueue::PacketQueue() {
  delete this->rawPacket;
}
