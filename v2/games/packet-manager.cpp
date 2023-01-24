#include "F1-2020/packets-structures/global-packet-F12020.h"
#include "packet-manager.h"
#include "packet-type.h"
#include "packet-wrapper.h"
#include <string.h>
#include <queue>

//Constructeur
PacketManager::PacketManager(Games *currentGame) {
  this->currentGame = currentGame;
  //Choix du paquet global selon le jeu
  switch (currentGame->getCurrentGame()) {
    case F1_2020:
      this->globalPacket = new GlobalPacketF120{};
      break;
    default:
      this->globalPacket = new GlobalPacketF120{};
      break;
  }
}

//Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
void PacketManager::handlePacket(char* rawPacket, size_t rawPacketSize, queue<PacketWrapper> *q) {
  //On enregistre le paquet reçu
  this->packetType = this->globalPacket->update(rawPacket, &rawPacketSize, q);
  if (this->packetType == nullptr) {
    //Le paquet ne semble pas être conforme
    return;
  }
  //Création du paquet wrapper pour envoi vers la queue
  PacketWrapper packetWrapper{&rawPacketSize, *this->packetType};
  q->push(packetWrapper);
}

//Destructeur
PacketManager::~PacketManager() {
  delete this->globalPacket;
}
