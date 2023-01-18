#include "data-listener/data-listener.h"
#include "games/games.h"

int main(int argc, char *argv[]) {
  Games selectedGame(game::F1_2020);
  DataListener listener("20778", selectedGame);
  //On démarre l'écoute
  listener.startListener();
}
