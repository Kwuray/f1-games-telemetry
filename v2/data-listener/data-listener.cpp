#include "data-listener.h"
#include "../games/games.h"
#include "../games/packet-manager.h"
#include "../games/packet-type.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <queue>
#include <memory>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
using namespace std;

DataListener::DataListener(char *port, Games *currentGame) { //Constructeur
  //Ajout du jeu en cours
  this->currentGame = currentGame;
  //Paramétrage de la socket
  this->gameAddressSize = sizeof(this->gameAddress);
  this->port = port; //n° de port
  memset(&hints, 0, sizeof hints); //Remise à zéro de hints
  this->hints.ai_family = AF_INET; //IPv4
  this->hints.ai_socktype = SOCK_DGRAM; //UDP type
  this->hints.ai_flags = AI_PASSIVE; //L'adresse IP de la machine obtenu automatiquement
  //Allocation dynamique de la variable qui reçoit le paquet
  this->rawPacket = new char[this->currentGame->getMaxPacketSize()];
  this->yes = 1;
  this->stop = false;
}

//Initialisation de la socket
int DataListener::initSocket() {
  //Paramétrage de l'adresse
  if ((getaddrinfo(NULL, this->port, &this->hints, &this->res)) != 0) {
    return -1;
  }
  //Création de la socket
  this->appSocket = socket(this->res->ai_family, this->res->ai_socktype, this->res->ai_protocol);
  if (appSocket == INVALID_SOCKET) {
    return -1;
  }
  //Ici, l'on va ignorer l'erreur "address already in use"
  setsockopt(appSocket, SOL_SOCKET, SO_REUSEADDR, &this->yes, sizeof this->yes);
  //Ici, nous allons définir le timeout de 5sec
  socketTimeout.tv_sec = 5;
  socketTimeout.tv_usec = 5000;
  setsockopt(appSocket, SOL_SOCKET, SO_RCVTIMEO, &socketTimeout, sizeof socketTimeout);

  //Activation du mode "Écoute"
  if ((::bind(this->appSocket, this->res->ai_addr, this->res->ai_addrlen)) == INVALID_SOCKET) {
    return -1;
  }
  return 0;
}

//Démarrage de l'écoute
void DataListener::listen(queue<unique_ptr<PacketType>> *q) {
  //Initialisation du packetManager
  PacketManager packetManager{this->currentGame};
  //Récupération en boucle de tous les paquets
  while (this->stop == false) {
    this->rawPacketSize = recvfrom(this->appSocket, this->rawPacket, this->currentGame->getMaxPacketSize(), 0, NULL, &this->gameAddressSize);
    //Si l'on reçoit bien un paquet
    if (this->rawPacketSize > 0) {
      packetManager.handlePacket(this->rawPacket, static_cast<size_t>(this->rawPacketSize), q);
    }
  }
}

//Destructeur
DataListener::~DataListener() {
  delete [] this->rawPacket;
}
