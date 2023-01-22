#include "packet-queue.h"

//constructor
PacketQueue::PacketQueue(char *rawPacket, int packetSize) {
  this->rawPacket = new char[packetSize];
  this->rawPacket = *rawPacket;
}

//destructor
PacketQueue::PacketQueue() {
  delete this->rawPacket;
}
