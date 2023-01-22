#ifndef GLOBAL_PACKET_F120_H
#define GLOBAL_PACKET_F120_H
#define F120_TOTAL_PACKET_TYPE 10
#include "../global-packet.h"
#include "../packet-type.h"
#include "packets-structures/car-setup.h"
#include "packets-structures/car-status.h"
#include "packets-structures/car-telemetry.h"
#include "packets-structures/event.h"
#include "packets-structures/final-classification.h"
#include "packets-structures/header.h"
#include "packets-structures/lap.h"
#include "packets-structures/lobby-info.h"
#include "packets-structures/motion.h"
#include "packets-structures/participants.h"
#include "packets-structures/session.h"
#include <stddef.h>
#include <string.h>

class GlobalPacketF120 : public GlobalPacket {
private:
  //Tous les différents paquets
  packetHeaderF120 header;
  PacketMotionDataObj motion();
  PacketSessionDataObj session();
  PacketLapDataObj lap();
  PacketEventDataObj event();
  PacketParticipantsDataObj participants();
  PacketCarSetupDataObj setup();
  PacketCarTelemetryDataObj telemetry();
  PacketCarStatusDataObj carStatus();
  PacketFinalClassificationDataObj finalClassification();
  PacketLobbyInfoDataObj lobbyInfo();
  //Liste des adresses des paquets
  PacketType *packetsAdresses[F120_TOTAL_PACKET_TYPE];
  //Mise à jour du paquet global, retourne l'adresse du paquet
  GlobalPacket *update(char *rawPacket, ssize_t *rawPacketSize);

public:
  //Constructeur
  GlobalPacketF120();
};

#endif
