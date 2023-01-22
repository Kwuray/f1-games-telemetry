#include "final-classification.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketFinalClassificationDataObj::loadData(char *data, ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->finalClassification)) {
    return false;
  }
  memcpy(&this->finalClassification, data, dataSize);
}

//Fonction de debug
void PacketFinalClassificationDataObj::debug() {
  printf("Hello world\n");
}
