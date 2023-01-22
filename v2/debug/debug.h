#ifndef DEBUG_THREAD_H
#define DEBUG_THREAD_H
#include "../games/packet-type.h"

class DebugThread {
private:
  bool quit;
public:
  //permet de démarrer le debug
  void start(queue<PacketType> *debugQueue);
  void stop();
};

#endif
