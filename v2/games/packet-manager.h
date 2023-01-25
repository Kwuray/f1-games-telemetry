#ifndef PACKET_MANAGER_H
#define PACKET_MANAGER_H
#include "games.h"
#include "global-packet.h"
#include "packet-type.h"
#include <string.h>
#include <queue>
#include <memory>
using namespace std;

class PacketManager {
private:
  Games *currentGame;
  GlobalPacket *globalPacket;
public:
  //Constructeur
  PacketManager(Games *currentGame);
  //Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
  void handlePacket(char* rawPacket, size_t rawPacketSize, queue<unique_ptr<PacketType>> *q);
  //Destructeur
  ~PacketManager();
};

#endif
