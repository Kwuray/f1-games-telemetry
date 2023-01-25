#include "session.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketSessionDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->session)) {
    return false;
  }
  memcpy(&this->session, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketSessionDataObj::debug() {
  printf("Hello world\n");
}

//Fonction de clonage
unique_ptr<PacketType> PacketSessionDataObj::clone() {
  return make_unique<PacketSessionDataObj>(*this);
}
