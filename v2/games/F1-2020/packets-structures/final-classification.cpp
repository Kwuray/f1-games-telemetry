#include "final-classification.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketFinalClassificationDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->finalClassification)) {
    return false;
  }
  memcpy(&this->finalClassification, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketFinalClassificationDataObj::debug() {
  printf("Hello world\n");
}

//Fonction de clonage
unique_ptr<PacketFinalClassificationDataObj> PacketFinalClassificationDataObj::clone() {
  return make_unique<PacketFinalClassificationDataObj>(*this);
}
