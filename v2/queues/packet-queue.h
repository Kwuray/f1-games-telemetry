#ifndef PACKET_QUEUE_H
#define PACKET_QUEUE_H

class PacketQueue {
private:
  char *rawPacket;

public:
  //constructor
  PacketQueue(char *rawPacket);
  //destructor
  ~PacketQueue();

};

#endif
