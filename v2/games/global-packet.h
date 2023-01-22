#ifndef GLOBAL_PACKET_H
#define GLOBAL_PACKET_H
#include <string.h>

class GlobalPacket {
public:
  //Constructeur
  GlobalPacket();
  //Mise à jour du paquet global, retourne l'adresse du paquet
  virtual void *update(char *rawPacket, ssize_t *rawPacketSize) = 0;
};

#endif
