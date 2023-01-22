#include "global-packet-F12020.h"
#include <string.h>
#include <stdio.h>

//Constructeur
GlobalPacketF120::GlobalPacketF120() {
  //Pour chaque paquet, on enregistre son adresse.
  this->packetsAdresses[0] = &this->motion;
  this->packetsAdresses[1] = &this->session;
  this->packetsAdresses[2] = &this->lap;
  this->packetsAdresses[3] = &this->event;
  this->packetsAdresses[4] = &this->participants;
  this->packetsAdresses[5] = &this->setup;
  this->packetsAdresses[6] = &this->telemetry;
  this->packetsAdresses[7] = &this->carStatus;
  this->packetsAdresses[8] = &this->finalClassification;
  this->packetsAdresses[9] = &this->lobbyInfo;
}

//Mis à jour du paquet global
GlobalPacket* GlobalPacketF120::update(char *rawPacket, ssize_t *rawPacketSize) {
  //On ne continu que si le paquet contient au moins un header
  if (*rawPacketSize < sizeof(this->header)) {
    return false;
  }
  //Enregistrement du header
  memcpy(&this->header, rawPacket, sizeof(this->header));
  //Enregistrement du nouveau paquet
  //Si le paquet n'a pas pu être enregistré, on retourne null
  if (!this->packetsAdresses[this->header.m_packetId]->loadData(rawPacket, rawPacketSize)) {
    return nullptr;
  }
  //On peut retourner l'adresse du nouveau paquet
  return this->packetsAdresses[this->header.m_packetId];
}
