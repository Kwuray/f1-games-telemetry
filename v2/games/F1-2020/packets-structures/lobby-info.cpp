#include "lobby-info.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketLobbyInfoDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->lobbyInfo)) {
    return false;
  }
  memcpy(&this->lobbyInfo, data, *dataSize);
  return true;
}

//Fonction de debug
void PacketLobbyInfoDataObj::debug() {
  printf("Hello world\n");
}
