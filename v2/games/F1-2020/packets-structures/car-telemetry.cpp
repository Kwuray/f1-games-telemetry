#include "car-telemetry.h"
#include <string.h>
#include <stdio.h>
#include <memory>
using namespace std;

//Permet de charger les données
bool PacketCarTelemetryDataObj::loadData(char *data, size_t *dataSize) {
  //On vérifie tout d'abord que la taille est cohérente
  if (*dataSize != sizeof(this->carTelemetry)) {
    return false;
  }
  memcpy(&this->carTelemetry, data, *dataSize);
  return true;
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

//Fonction de clonage
unique_ptr<PacketCarTelemetryDataObj> PacketCarTelemetryDataObj::clone() {
  return make_unique<PacketCarTelemetryDataObj>(*this);
}
