#ifndef PACKET_QUEUE_H
#define PACKET_QUEUE_H

class PacketQueue {
private:
  char *rawPacket;

public:
  //constructor
  PacketQueue(int *maxPacketSize, char *rawPacket);
  //destructor
  ~PacketQueue();

};

#endif
