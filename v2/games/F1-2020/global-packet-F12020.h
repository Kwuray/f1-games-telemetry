#ifndef GLOBAL_PACKET_F120_H
#define GLOBAL_PACKET_F120_H
#define F120_TOTAL_PACKET_TYPE 10

#include "packets-structures/carSetup.h"
#include "packets-structures/carStatus.h"
#include "packets-structures/carTelemetry.h"
#include "packets-structures/event.h"
#include "packets-structures/finalClassification.h"
#include "packets-structures/header.h"
#include "packets-structures/lapData.h"
#include "packets-structures/lobbyInfo.h"
#include "packets-structures/motion.h"
#include "packets-structures/participants.h"
#include "packets-structures/session.h"
#include <stddef.h>

class GlobalPacketF120 {
private:
  //Tous les différents paquets
  packetHeaderF120 header;
  packetMotionData motion;
  packetSessionData session;
  packetLapData lap;
  packetEventData event;
  packetParticipantsData participants;
  packetCarSetupData setup;
  packetCarTelemetryData telemetry;
  packetCarStatusData carStatus;
  packetFinalClassificationData finalClassification;
  packetLobbyInfoData lobbyInfo;
  //Liste des adresses des paquets
  void *packetsAdresses[F120_TOTAL_PACKET_TYPE];
  //Liste de la taille des différents paquets
  size_t packetsSizes[F120_TOTAL_PACKET_TYPE];
  //Permet de vérifier la conformité du paquet
  bool isPacketOk(char *rawPacket, int *rawPacketSize);
  //Fonction de debug
  void debug();

public:
  //Constructeur
  GlobalPacketF120();
  //Mise à jour du paquet global, retourne l'adresse du paquet
  void *update(char *rawPacket, int *rawPacketSize);
};

#endif
