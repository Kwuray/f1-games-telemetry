#ifndef DEBUG_THREAD_H
#define DEBUG_THREAD_H
#include "../games/packet-wrapper.h"

class DebugThread {
private:
  bool quit;
public:
  //permet de démarrer le debug
  void start(queue<PacketWrapper> *q);
  void stop();
};

#endif
