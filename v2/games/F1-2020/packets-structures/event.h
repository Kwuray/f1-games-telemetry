//*-*-*-*-*-*-*-*-*-*-*-*-*-*-//
// This packet gives details of events that happen during the course of a session.

// Frequency: When the event occurs
// Size: 35 bytes (Packet size updated in Beta 3)
// Version: 1

// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-//

#ifndef DEF_F120PACKEVENT
#define DEF_F120PACKEVENT

#include "header.h"
#include "../../packet-type.h"
#include <stdint.h>
#include <string.h>

union eventDataDetails {

  struct __attribute__((packed)) {
    uint8_t	        vehicleIdx; // Vehicle index of car achieving fastest lap
    float	          lapTime;    // Lap time is in seconds
  } FastestLap;

  struct __attribute__((packed)) {
    uint8_t         vehicleIdx; // Vehicle index of car retiring
  } Retirement;

  struct __attribute__((packed)) {
      uint8_t       vehicleIdx; // Vehicle index of team mate
  } TeamMateInPits;

  struct __attribute__((packed)) {
      uint8_t       vehicleIdx; // Vehicle index of the race winner
  } RaceWinner;

  struct __attribute__((packed)) {
  	uint8_t         penaltyType;          // Penalty type – see Appendices
    uint8_t         infringementType;     // Infringement type – see Appendices
    uint8_t         vehicleIdx;           // Vehicle index of the car the penalty is applied to
    uint8_t         otherVehicleIdx;      // Vehicle index of the other car involved
    uint8_t         time;                 // Time gained, or time spent doing action in seconds
    uint8_t         lapNum;               // Lap the penalty occurred on
    uint8_t         placesGained;         // Number of places gained by this
  } Penalty;

  struct __attribute__((packed)) {
      uint8_t       vehicleIdx;   // Vehicle index of the vehicle triggering speed trap
      float         speed;        // Top speed achieved in kilometres per hour
  } SpeedTrap;
};


struct __attribute__((packed)) packetEventData {

  struct packetHeaderF120    	  m_header;             // Header

  uint8_t           	      m_eventStringCode[4]; // Event string code, see below
  union eventDataDetails	  m_eventDetails;       // Event details - should be interpreted differently
                                              // for each type
};

class PacketEventDataObj : public PacketType {
private:
  packetEventData event;

public:
  //Permet de charger les données, renvoi si oui ou non cela a été fait
  bool loadData(char *data, size_t *dataSize);
  //Fonction de debug
  void debug();

};

#endif
