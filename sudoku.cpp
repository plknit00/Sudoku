#include "sudoku.h"
#include <cerrno>
#include <cstdint>
#include <iostream>
#include <optional>
#include <string>
using namespace std;

Sudoku::Sudoku() : board{0}, empty_cells(81){};

void Sudoku::print_board() {
  cout << " - - - - - - - - - - - -" << endl;
  for (int roww = 0; roww < 9; roww++) {
    cout << "|";
    for (int colm = 0; colm < 3; colm++) {
      cout << " ";
      if (board[roww][3 * colm] == 0) {
        cout << "*";
      } else {
        cout << board[roww][3 * colm];
      }
      cout << " ";
      if (board[roww][3 * colm + 1] == 0) {
        cout << "*";
      } else {
        cout << board[roww][3 * colm + 1];
      }
      cout << " ";
      if (board[roww][3 * colm + 2] == 0) {
        cout << "*";
      } else {
        cout << board[roww][3 * colm + 2];
      }
      cout << " |";
    }
    cout << endl;
    if (roww % 3 == 2) {
      cout << " - - - - - - - - - - - -" << endl;
    }
  }
}

void Sudoku::set_starter_board_easy() {
  board[0][1] = 3;
  board[0][8] = 1;
  board[1][0] = 9;
  board[1][2] = 7;
  board[1][4] = 8;
  board[1][7] = 3;
  board[2][1] = 8;
  board[2][3] = 2;
  board[2][5] = 4;
  board[2][6] = 6;
  board[3][0] = 4;
  board[3][3] = 6;
  board[3][5] = 7;
  board[3][6] = 3;
  board[3][7] = 1;
  board[4][0] = 8;
  board[4][1] = 7;
  board[4][4] = 2;
  board[4][8] = 9;
  board[5][2] = 3;
  board[5][3] = 1;
  board[5][7] = 4;
  board[5][8] = 2;
  board[6][1] = 1;
  board[6][7] = 8;
  board[7][0] = 5;
  board[7][2] = 2;
  board[7][4] = 6;
  board[7][7] = 7;
  board[8][3] = 3;
  board[8][5] = 5;
  board[8][6] = 4;
  board[8][8] = 6;
  empty_cells = 48;
}

void Sudoku::instructions() {
  cout << endl;
  cout << "Welcome to Sudoku!" << endl;
  cout << "You must fill every blank space, *, with a number 1-9." << endl;
  cout << "In the final board, every row will contain exactly one of each "
          "number 1-9,"
       << endl;
  cout << "every column will contain exactly one of each number 1-9," << endl;
  cout << "and every box will contain exactly one of each number 1-9." << endl;
  cout << "The input will ask you for a row, column, and value." << endl;
  cout << "The rows count from 1-9 starting from the top going down." << endl;
  cout << "The columns count from 1-9 starting from left to right." << endl;
  cout << "The value must be a number between 1-9," << endl;
  cout << "and the game will check if it is valid for the selected location."
       << endl;
  cout << "Good luck!" << endl;
  cout << endl;
}

bool Sudoku::good_value(long int val) { return (val >= 1 && val <= 9); }

bool Sudoku::cell_empty(int row, int col) { return board[row][col] == 0; }

int Sudoku::prompt_for_digit(const string &prompt) {
  string str;
  cout << prompt << ": ";
  getline(cin, str);
  char *pEnd;
  // attempts to switch str input to integer
  // strtol changes pEnd to point to one past
  // the last character parsed in str
  long int val = strtol(str.c_str(), &pEnd, 10);
  // they will be equal if ptr is an int
  while (((str.c_str() + str.size()) != pEnd) || !good_value(val)) {
    cout << "Invalid input. This value must be a number 1-9." << endl;
    cout << prompt << ": ";
    getline(cin, str);
    val = strtol(str.c_str(), &pEnd, 10);
  }
  return static_cast<int>(val);
}

void Sudoku::game_input() {
  int row = prompt_for_digit("Row");
  int col = prompt_for_digit("Col");
  int val = prompt_for_digit("Value");
  row--;
  col--;
  if (!cell_empty(row, col)) {
    cout << "This cell already has a number in it. Please try again." << endl;
  } else if (!valid_entry(row, col, val)) {
    cout << "This value breaks the rules of sudoku. Please try again." << endl;
  } else {
    board[row][col] = val;
    empty_cells--;
  }
}

bool Sudoku::check_row(int col, int val) {
  for (int row = 0; row < 9; row++) {
    if (val == board[row][col]) {
      return false;
    }
  }
  return true;
}

bool Sudoku::check_col(int row, int val) {
  for (int col = 0; col < 9; col++) {
    if (val == board[row][col]) {
      return false;
    }
  }
  return true;
}

bool Sudoku::check_box(int row, int col, int val) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (val == board[3 * (row / 3) + r][3 * (col / 3) + c]) {
        return false;
      }
    }
  }
  return true;
}

bool Sudoku::valid_entry(int r, int c, int v) {
  return check_row(c, v) && check_col(r, v) && check_box(r, c, v);
}

bool Sudoku::finished() { return empty_cells == 0; }

// Solves the board and prints solution
void Sudoku::solve() {
  // solve stuff
  print_board();
}