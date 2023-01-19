#include "games.h"

//Constructeur
Games::Games(game currentGame) {
  this->currentGame = currentGame;
  this->setMaxPacketSize();
}

//setter maxPacketSize
void Games::setMaxPacketSize() {
  switch (this->getCurrentGame()) {
    case F1_2020:
      this->maxPacketSize = 1464;
      break;
    default:
      this->maxPacketSize = 1464;
      break;
  }
}

//getter maxPacketSize
int Games::getMaxPacketSize() {
  return this->maxPacketSize;
}

//getter currentGame
game Games::getCurrentGame() {
  return this->currentGame;
}
