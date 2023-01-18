#include "data-listener.h"
#include "../games/games.h"
#include "../games/packet-manager.h"
#include <string.h>

DataListener::DataListener(char *port, Games *currentGame) { //Constructeur
  //Ajout du jeu en cours
  this->currentGame = currentGame;
  //Paramétrage de la socket
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
  if (appSocket == -1) {
    return -1;
  }
  //Ici, l'on va ignorer l'erreur "address already in use"
  setsockopt(appSocket, SOL_SOCKET, SO_REUSEADDR, &this->yes, sizeof this->yes);
  //Ici, nous allons définir le timeout de 5sec
  socketTimeout.tv_sec = 5;
  socketTimeout.tv_usec = 5000;
  setsockopt(appSocket, SOL_SOCKET, SO_RCVTIMEO, &socketTimeout, sizeof socketTimeout);
  return 0;
}

//Démarrage du listener
int DataListener::startListener() {
  //Initialisation de la socket
  if (this->initSocket() == -1) {
    return -1;
  }

  //Activation du mode "Écoute"
  if ((bind(this->appSocket, this->res->ai_addr, this->res->ai_addrlen)) == -1) {
    return -1;
  }
  //Création des différents threads annexes
  //...

  //Initialisation du packetManager
  PacketManager packetManager(this->currentGame);

  //Récupération en boucle de tous les paquets
  while (stop == false) {
    this->rawPacketSize = recvfrom(this->appSocket, this->rawPacket, sizeof this->rawPacket, 0, NULL, &this->gameAddressSize);
    packetManager.handlePacket(this->rawPacket, &this->rawPacketSize);
  }
  return 0;
}

//Permet d'écouter les signaux UNIX
void DataListener::sigintHandler(int sig) {
  this->stop = true;
}

//Destructeur
DataListener::~DataListener() {
  delete this->rawPacket;
}
