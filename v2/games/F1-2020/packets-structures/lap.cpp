#include "lap.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketLapDataObj::loadData(char *data[], ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->lap)) {
    return false;
  }
  memcpy(&this->lap, data, dataSize);
}

//Fonction de debug
void PacketLapDataObj::debug() {
  printf("Hello world\n");
}
