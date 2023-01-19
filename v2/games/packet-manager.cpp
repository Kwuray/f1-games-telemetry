#include "packet-manager.h"
#include "F1-2020/global-packet-F12020.h"
#include <string.h>

//Constructeur
PacketManager::PacketManager(Games *currentGame) {
  this->currentGame = currentGame;
  switch (currentGame->getCurrentGame()) {
    case F1_2020:
      this->globalPacket = new GlobalPacketF120();
      break;
    default:
      this->globalPacket = new GlobalPacketF120();
      break;
  }
  //Création des différentes queues
}

//Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
void PacketManager::handlePacket(char* rawPacket, ssize_t *rawPacketSize) {
  //On enregistre le paquet reçu
  void *savedPacket;
  //On cast le pointeur différemment selon le jeu
  switch (this->currentGame->getCurrentGame()) {
    case F1_2020:
      savedPacket = static_cast<GlobalPacketF120*>(this->globalPacket)->update(rawPacket, rawPacketSize);
      break;
    default:
      savedPacket = static_cast<GlobalPacketF120*>(this->globalPacket)->update(rawPacket, rawPacketSize);
      break;
  }
  if (savedPacket == NULL) {
    //Le paquet ne semble pas être conforme
    return;
  }

  //Envoi vers les différentes queues
}

//Destructeur
PacketManager::~PacketManager() {
  switch (this->currentGame->getCurrentGame()) {
    case F1_2020:
      delete static_cast<GlobalPacketF120*>(this->globalPacket);
      break;
    default:
      delete static_cast<GlobalPacketF120*>(this->globalPacket);
      break;
  }
}
