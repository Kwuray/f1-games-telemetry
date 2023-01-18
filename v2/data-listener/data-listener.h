#ifndef DATA_LISTENER_H
#define DATA_LISTENER_H
#include "../games/games.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>

class DataListener {
private:
  socklen_t gameAddressSize;
  struct addrinfo hints, *res; //Ces structures de données contiendront les informations de connexion de l'application
  int appSocket; //Ici, la socket qui servira à enclencher la connexion
  char* rawPacket; //Contiendra les données reçues
  int rawPacketSize;
  struct timeval socketTimeout;
  char *port;
  int yes; //Servira à éviter l'erreur address already in use
  Games *currentGame;
  bool stop;

  //Initialisation de la socket (renvoi -1 si erreur)
  int initSocket();
  //Permet d'écouter les signaux UNIX
  void sigintHandler(int sig);

public:
  //Constructeur
  DataListener(char* port, Games *currentGame);
  //Destructeur
  ~DataListener();
  //Démarrage du listener (renvoi -1 si erreur)
  int startListener();
};

#endif