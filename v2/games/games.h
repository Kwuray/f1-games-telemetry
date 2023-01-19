#ifndef GAMES_H
#define GAMES_H

enum game {
  F1_2022,
  F1_2021,
  F1_2020
};

class Games {
private:
  game currentGame;
  int maxPacketSize;

public:
  //Constructeur
  Games(game currentGame);
  //getter currentGame
  game getCurrentGame();
  //setter maxPacketSize
  void setMaxPacketSize();
  //getter maxPacketSize
  int getMaxPacketSize();
};

#endif
