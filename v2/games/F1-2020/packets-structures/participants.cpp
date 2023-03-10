#include "participants.h"
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

//Permet de charger les données
bool PacketParticipantsDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->participants)) {
    return false;
  }
  memcpy(&this->participants, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketParticipantsDataObj::debug() {
  printf("Hello world\n");
}

//Fonction de clonage
unique_ptr<PacketType> PacketParticipantsDataObj::clone() {
  return make_unique<PacketParticipantsDataObj>(*this);
}
