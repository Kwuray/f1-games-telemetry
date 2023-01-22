#include "event.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketEventDataObj::loadData(char *data, ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->event)) {
    return false;
  }
  memcpy(&this->event, data, dataSize);
}

//Fonction de debug
void PacketEventDataObj::debug() {
  printf("Hello world\n");
}
