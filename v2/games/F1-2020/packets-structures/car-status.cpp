#include "car-status.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketCarStatusDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->carStatus)) {
    return false;
  }
  memcpy(&this->carStatus, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketCarStatusDataObj::debug() {
  printf("Hello world\n");
}

//Fonction de clonage
unique_ptr<PacketCarStatusDataObj> PacketCarStatusDataObj::clone() {
  return make_unique<PacketCarStatusDataObj>(*this);
}
