#ifndef PACKET_TYPE_H
#define PACKET_TYPE_H
#include <string.h>

class PacketType {

public:
  //Permet de charger les données, renvoi si oui ou non cela a été fait
  virtual bool loadData(char *data, size_t *dataSize) = 0;
  //Fonction de debug
  virtual void debug() = 0;

};

#endif
