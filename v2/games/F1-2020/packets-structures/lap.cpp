#include "lap.h"
#include <string.h>
#include <stdio.h>

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
