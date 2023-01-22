#include "participants.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketParticipantsDataObj::loadData(char *data[], ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->motion)) {
    return false;
  }
  memcpy(&this->motion, data, dataSize);
}

//Fonction de debug
void PacketParticipantsDataObj::debug() {
  printf("Hello world\n");
}
