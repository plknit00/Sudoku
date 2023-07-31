#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

#include "sudoku.h"
using namespace std;

int main() {
  Sudoku S;
  S.set_starter_board_easy();
  S.instructions();
  while (!S.finished()) {
    S.print_board();
    S.game_input();
  }
  return 0;
}