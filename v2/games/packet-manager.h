#ifndef PACKET_MANAGER_H
#define PACKET_MANAGER_H
#include "games.h"
#include "global-packet.h"
#include "queues/packet-queue.h"
#include <string.h>
#include <queue>

class PacketManager {
private:
  Games *currentGame;
  GlobalPacket *globalPacket;

public:
  //Constructeur
  PacketManager(Games *currentGame);
  //Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
  void handlePacket(char* rawPacket, ssize_t *rawPacketSize, queue<PacketQueue> *q);
  //Destructeur
  ~PacketManager();
};

#endif
