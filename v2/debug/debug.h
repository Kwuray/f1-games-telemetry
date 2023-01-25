#ifndef DEBUG_THREAD_H
#define DEBUG_THREAD_H
#include "../games/packet-type.h"
#include <queue>
#include <memory>
using namespace std;

class DebugThread {
private:
  bool quit;
public:
  //permet de démarrer le debug
  void start(queue<unique_ptr<PacketType>> *q);
  void stop();
};

#endif
