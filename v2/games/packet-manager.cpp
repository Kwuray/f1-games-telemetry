#include "F1-2020/packets-structures/global-packet-F12020.h"
#include "packet-manager.h"
#include "packet-type.h"
#include <string.h>
#include <queue>
#include <memory>
using namespace std;

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
void PacketManager::handlePacket(char* rawPacket, size_t rawPacketSize, queue<unique_ptr<PacketType>> *q) {
  //On enregistre le paquet reçu
  PacketType *packetType = this->globalPacket->update(rawPacket, &rawPacketSize);
  if (packetType == nullptr) {
    //Le paquet ne semble pas être conforme
    return;
  }
  //On ajoute une copie de l'objet dans la queue
  q->push(packetType->clone());
}

//Destructeur
PacketManager::~PacketManager() {
  delete this->globalPacket;
}
