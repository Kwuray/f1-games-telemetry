#include "motion.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketMotionDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->motion)) {
    return false;
  }
  memcpy(&this->motion, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketMotionDataObj::debug() {
  printf("Hello world\n");
}
