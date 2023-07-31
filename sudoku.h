#include <cstdint>
#include <iostream>
#include <optional>
#include <string>
using namespace std;

class Sudoku {
private:
  int board[9][9];
  int empty_cells;

public:
  // CONSTRUCTOR
  Sudoku();

  // Prints the board at every step
  void print_board();

  // Fills in starting values for an easy board
  void set_starter_board_easy();

  // Gives user list of rules to play the game
  void instructions();

  // Checks if an input is a value 1-9
  bool good_value(int val);

  // Checks if a cell is empty
  bool cell_empty(int row, int col);

  /**
   * Continually promtps user for digit 1-9 until one is given
   */
  int prompt_for_digit(const string &prompt);

  // Takes in information from user on row and column number
  // along with entry attempt, it is checked if it is valid
  void game_input();

  // Checks that a new entry is not a repeat within a row
  // returns true if it is a valid entry
  bool check_row(int col, int val);

  // Checks that a new entry is not a repeat within a column
  // returns true if it is a valid entry
  bool check_col(int row, int val);

  // Checks that a new entry is not a repeat within a box
  // returns true if it is a valid entry
  bool check_box(int row, int col, int val);

  // returns true if it is a valid entry
  bool valid_entry(int r, int c, int v);

  // When the board is full and all entries are valid, game is finished
  bool finished();
};