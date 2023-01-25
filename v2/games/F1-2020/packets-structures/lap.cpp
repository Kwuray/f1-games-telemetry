#include "lap.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketLapDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->lap)) {
    return false;
  }
  memcpy(&this->lap, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketLapDataObj::debug() {
  printf("Hello world\n");
}

//Fonction de clonage
unique_ptr<PacketType> PacketLapDataObj::clone() {
  return make_unique<PacketLapDataObj>(*this);
}
