#ifndef GLOBAL_PACKET_H
#define GLOBAL_PACKET_H
#include "packet-wrapper.h"
#include <queue>
#include <string.h>
using namespace std;

class GlobalPacket {
public:
  //Constructeur
  GlobalPacket();
  //Mise à jour du paquet global, retourne l'adresse du paquet
  virtual PacketType* update(char *rawPacket, size_t *rawPacketSize, queue<PacketWrapper> *q) = 0;
  //Destructeur
  virtual ~GlobalPacket() = 0;
};

#endif
