#include "session.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketSessionDataObj::loadData(char *data[], ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->session)) {
    return false;
  }
  memcpy(&this->session, data, dataSize);
}

//Fonction de debug
void PacketSessionDataObj::debug() {
  printf("Hello world\n");
}
