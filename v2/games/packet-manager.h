#ifndef PACKET_MANAGER_H
#define PACKET_MANAGER_H
#include "games.h"
#include <string.h>

class PacketManager {
private:
  Games *currentGame;
  void *globalPacket;

public:
  //Constructeur
  PacketManager(Games *currentGame);
  //Permet de gérer un paquet reçu, vérifier sa conformité, l'enregistrer et l'envoyer vers les queues
  void handlePacket(char* rawPacket, ssize_t *rawPacketSize);
  //Destructeur
  ~PacketManager();
};

#endif
