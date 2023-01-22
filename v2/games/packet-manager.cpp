#include "F1-2020/global-packet-F12020.h"
#include "packet-manager.h"
#include "packet-type.h"
#include "packet-type.h"
#include <string.h>
#include <queue>

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
}

//Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
void PacketManager::handlePacket(char* rawPacket, ssize_t *rawPacketSize, queue<PacketType> *q) {
  //Si le paquet n'a pas bien été enregistré, on quitte la fonction
  if (!this->globalPacket->update(rawPacket, rawPacketSize)) {
    return
  }
  //On enregistre le paquet reçu
  GlobalPacket *savedPacket = this->globalPacket->update(rawPacket, rawPacketSize);
  if (savedPacket == nullptr) {
    //Le paquet ne semble pas être conforme
    return;
  }
  //Envoi vers les différentes queues
  q->push(*savedPacket);
}

//Destructeur
PacketManager::~PacketManager() {
  delete this->globalPacket;
}
