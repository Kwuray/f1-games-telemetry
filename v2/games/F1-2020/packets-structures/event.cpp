#include "event.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketEventDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->event)) {
    return false;
  }
  memcpy(&this->event, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketEventDataObj::debug() {
  printf("Hello world\n");
}

//Fonction de clonage
unique_ptr<PacketEventDataObj> PacketEventDataObj::clone() {
  return make_unique<PacketEventDataObj>(*this);
}