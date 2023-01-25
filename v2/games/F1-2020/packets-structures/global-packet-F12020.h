#ifndef GLOBAL_PACKET_F120_H
#define GLOBAL_PACKET_F120_H
#define F120_TOTAL_PACKET_TYPE 10
#include "../../global-packet.h"
#include "../../packet-type.h"
#include "car-setup.h"
#include "car-status.h"
#include "car-telemetry.h"
#include "event.h"
#include "final-classification.h"
#include "header.h"
#include "lap.h"
#include "lobby-info.h"
#include "motion.h"
#include "participants.h"
#include "session.h"
#include <stddef.h>
#include <string.h>
using namespace std;

class GlobalPacketF120 : public GlobalPacket {
private:
  //Tous les différents paquets
  packetHeaderF120 header{};
  PacketMotionDataObj motion{};
  PacketSessionDataObj session{};
  PacketLapDataObj lap{};
  PacketEventDataObj event{};
  PacketParticipantsDataObj participants{};
  PacketCarSetupDataObj setup{};
  PacketCarTelemetryDataObj telemetry{};
  PacketCarStatusDataObj carStatus{};
  PacketFinalClassificationDataObj finalClassification{};
  PacketLobbyInfoDataObj lobbyInfo{};
  //Liste des paquets
  PacketType *packetsAdresses[F120_TOTAL_PACKET_TYPE];
  //Mise à jour du paquet global, retourne l'adresse du paquet
  PacketType* update(char *rawPacket, size_t *rawPacketSize);

public:
  //Constructeur
  GlobalPacketF120();
};

#endif
