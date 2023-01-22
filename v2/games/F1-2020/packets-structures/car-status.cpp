#include "car-status.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketCarStatusDataObj::loadData(char *data[], ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->carStatus)) {
    return false;
  }
  memcpy(&this->carStatus, data, dataSize);
}

//Fonction de debug
void PacketCarStatusDataObj::debug() {
  printf("Hello world\n");
}
