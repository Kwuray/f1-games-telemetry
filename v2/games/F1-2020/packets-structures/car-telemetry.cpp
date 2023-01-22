#include "car-telemetry.h"
#include <string.h>
#include <stdio.h>

//Permet de charger les données
bool PacketCarTelemetryDataObj::loadData(char *data[], ssize_t dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (dataSize != sizeof(this->carTelemetry)) {
    return false;
  }
  memcpy(&this->carTelemetry, data, dataSize);
}

//Fonction de debug
void PacketCarTelemetryDataObj::debug() {
  int playerIndex = this->carTelemetry.m_header.m_playerCarIndex;
  printf("--------------------"
  "\nSpeed : %u"
  "\nThrottle pressure : %f"
  "\nBrake pressure : %f"
  "\nGear selected : %u"
  "\nEngine PRM : %u"
  "\n--------------------",
  this->carTelemetry.m_carTelemetryData[playerIndex].m_speed,
  this->carTelemetry.m_carTelemetryData[playerIndex].m_throttle,
  this->carTelemetry.m_carTelemetryData[playerIndex].m_brake,
  this->carTelemetry.m_carTelemetryData[playerIndex].m_gear,
  this->carTelemetry.m_carTelemetryData[playerIndex].m_engineRPM);
}
