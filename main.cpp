#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

#include "print_csi.h"
#include "sudoku.h"
using namespace std;

int main() {
  Sudoku S;
  S.set_starter_board_easy();
  S.instructions();
  while (!S.finished()) {
    // eventually have text write overitself so terminal doesnt get super full
    // make board prettier
    S.print_board();
    S.game_input();
  }
  // **** MAKE A SOLVER ***************
  S.print_board();
  cout << "Congrats! You solved this sudoku puzzle!" << endl;
  return 0;
}