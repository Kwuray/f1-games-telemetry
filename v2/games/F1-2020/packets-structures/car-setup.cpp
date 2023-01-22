#include "car-setup.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketCarSetupDataObj::loadData(char *data[], ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->carSetup)) {
    return false;
  }
  memcpy(&this->carSetup, data, dataSize);
}

//Fonction de debug
void PacketCarSetupDataObj::debug() {
  printf("Hello world\n");
}
