#include "F1-2020/global-packet-F12020.h"
#include "packet-manager.h"
#include <string.h>

//Constructeur
PacketManager::PacketManager(Games *currentGame) {
  this->currentGame = currentGame;
  //Choix du paquet global selon le jeu
  switch (currentGame->getCurrentGame()) {
    case F1_2020:
      this->globalPacket = new GlobalPacketF120();
      break;
    default:
      this->globalPacket = new GlobalPacketF120();
      break;
  }
  //Création des différentes queues
  //...
}

//Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
void PacketManager::handlePacket(char* rawPacket, ssize_t *rawPacketSize) {
  //On enregistre le paquet reçu
  void *savedPacket = this->globalPacket->update(rawPacket, rawPacketSize);
  if (savedPacket == NULL) {
    //Le paquet ne semble pas être conforme
    return;
  }

  //Envoi vers les différentes queues
}

//Destructeur
PacketManager::~PacketManager() {
  delete this->globalPacket;
  /*
  switch (this->currentGame->getCurrentGame()) {
    case F1_2020:
      delete static_cast<GlobalPacketF120*>(this->globalPacket);
      break;
    default:
      delete static_cast<GlobalPacketF120*>(this->globalPacket);
      break;
  }
  */
}
