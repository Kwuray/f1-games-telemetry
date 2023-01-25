#include "car-setup.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketCarSetupDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->carSetup)) {
    return false;
  }
  memcpy(&this->carSetup, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketCarSetupDataObj::debug() {
  printf("Hello world\n");
}