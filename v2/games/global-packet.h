#ifndef GLOBAL_PACKET_H
#define GLOBAL_PACKET_H
#include "packet-type.h"
#include <string.h>
using namespace std;

class GlobalPacket {
public:
  //Mise à jour du paquet global, retourne l'adresse du paquet
  virtual PacketType* update(char *rawPacket, size_t *rawPacketSize) = 0;
  //Destructeur
  virtual ~GlobalPacket() = default;
};

#endif
