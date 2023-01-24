#ifndef DATA_LISTENER_H
#define DATA_LISTENER_H
#define INVALID_SOCKET -1

#include "../games/games.h"
#include "../games/packet-wrapper.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <queue>
using namespace std;

class DataListener {
private:
  struct sockaddr_in gameAddress; //Ici sera stocké les informations de connexion du jeu (ip..)
  socklen_t gameAddressSize;
  struct addrinfo hints, *res; //Ces structures de données contiendront les informations de connexion de l'application
  int appSocket; //Ici, la socket qui servira à enclencher la connexion
  char* rawPacket; //Contiendra les données reçues
  ssize_t rawPacketSize;
  struct timeval socketTimeout;
  char *port;
  int yes; //Servira à éviter l'erreur address already in use
  Games *currentGame;
  bool stop;

public:
  //Constructeur
  DataListener(char* port, Games *currentGame);
  //Initialisation de la socket (renvoi -1 si erreur)
  int initSocket();
  //Démarrage de l'écoute
  void listen(queue<PacketWrapper> *q);
  //Destructeur
  ~DataListener();
};

#endif
