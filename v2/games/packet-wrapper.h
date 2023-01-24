#ifndef PACKET_WRAPPER_H
#define PACKET_WRAPPER_H
#include "packet-type.h"
#include <string.h>

class PacketWrapper {
private:
  PacketType packet;
public:
  //Constructeur
  PacketWrapper(size_t *packetSize, PacketType packet);
  //getterPacket
  PacketType* getPacket();
  //Destructeur
  ~PacketWrapper();
};

#endif
