#include "packet-wrapper.h"
#include "packet-type.h"
#include <string.h>

//Constructeur
PacketWrapper::PacketWrapper(size_t *packetSize, PacketType packet) {
  //Création et copie du paquet
  this->packet = packet;//new PacketType[packetSize];
  //memcpy(&this->packet, (void*)packet, *packetSize);
}
//getterPacket
PacketType* PacketWrapper::getPacket() {
  return &this->packet;
}
//Destructeur
PacketWrapper::~PacketWrapper() {
  delete this->packet;
}
