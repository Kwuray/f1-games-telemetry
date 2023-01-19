#include "global-packet-F12020.h"
#include <string.h>
#include <stdio.h>

//Constructeur
GlobalPacketF120::GlobalPacketF120() {
  //Pour chaque paquet, on enregistre son adresse et sa taille.
  this->packetsAdresses[0] = &this->motion;
  this->packetsSizes[0] = sizeof(this->motion);

  this->packetsAdresses[1] = &this->session;
  this->packetsSizes[1] = sizeof(this->session);

  this->packetsAdresses[2] = &this->lap;
  this->packetsSizes[2] = sizeof(this->lap);

  this->packetsAdresses[3] = &this->event;
  this->packetsSizes[3] = sizeof(this->event);

  this->packetsAdresses[4] = &this->participants;
  this->packetsSizes[4] = sizeof(this->participants);

  this->packetsAdresses[5] = &this->setup;
  this->packetsSizes[5] = sizeof(this->setup);

  this->packetsAdresses[6] = &this->telemetry;
  this->packetsSizes[6] = sizeof(this->telemetry);

  this->packetsAdresses[7] = &this->carStatus;
  this->packetsSizes[7] = sizeof(this->carStatus);

  this->packetsAdresses[8] = &this->finalClassification;
  this->packetsSizes[8] = sizeof(this->finalClassification);

  this->packetsAdresses[9] = &this->lobbyInfo;
  this->packetsSizes[9] = sizeof(this->lobbyInfo);

}

//Permet de vérifier la conformité d'un paquet
bool GlobalPacketF120::isPacketOk(char *rawPacket, ssize_t *rawPacketSize) {
  packetHeaderF120 tmpHeader;
  //On vérifie tout d'abord qu'il y ait au moins un header dans le paquet
  if (*rawPacketSize < sizeof(tmpHeader)) {
    return false;
  }
  //Enregistrement du header temporaire
  memcpy(&tmpHeader, rawPacket, sizeof(tmpHeader));
  //On vérifie ensuite que la taille totale est cohérente
  if (*rawPacketSize != this->packetsSizes[tmpHeader.m_packetId]) {
    return false;
  }
  return true;
}

//Mis à jour du paquet global
void* GlobalPacketF120::update(char *rawPacket, ssize_t *rawPacketSize) {
  //On ne continu que si le paquet est conforme
  if (!this->isPacketOk(rawPacket, rawPacketSize)) {
    return NULL;
  }
  //Enregistrement du header
  memcpy(&this->header, rawPacket, sizeof(this->header));
  //Enregistrement du nouveau paquet
  memcpy(this->packetsAdresses[this->header.m_packetId], rawPacket, this->packetsSizes[this->header.m_packetId]);
  //Affichage des données reçues
  this->debug();
  //On renvoi l'adresse du paquet
  return this->packetsAdresses[this->header.m_packetId];
}

//fonction de debug
void GlobalPacketF120::debug() {
  uint8_t playerIndex = this->header.m_playerCarIndex;
  //Action différente selon le paquet
  switch (this->header.m_packetId) {
    case 6:
      printf("--------------------"
      "\nSpeed : %u"
      "\nThrottle pressure : %f"
      "\nBrake pressure : %f"
      "\nGear selected : %u"
      "\nEngine PRM : %u"
      "\n--------------------",
      this->telemetry.m_carTelemetryData[playerIndex].m_speed,
      this->telemetry.m_carTelemetryData[playerIndex].m_throttle,
      this->telemetry.m_carTelemetryData[playerIndex].m_brake,
      this->telemetry.m_carTelemetryData[playerIndex].m_gear,
      this->telemetry.m_carTelemetryData[playerIndex].m_engineRPM);
      break;
    default:
      break;
  }
}
