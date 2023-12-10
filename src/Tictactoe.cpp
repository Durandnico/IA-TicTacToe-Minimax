/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Tictactoe Minimax                                  :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 05/December/2023 by Durandnico      #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file Tictactoe.cpp
 *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 05 December 2023 - 15:19:13
 *
 *  \brief 
 *
 *
 */

// Inclusion des entetes de librairies
#include "../inc/Tictactoe.h"
#include <cstdint>
#include <iostream>

void
TicTacToe::initializeBoard()
{
  nbMoves = 0;
  for (char& cell : board) {
      cell = ' ';
  }
}

/* ------------------------------------- */

void
TicTacToe::switchPlayer()
{
  currentPlayer = (currentPlayer == X) ? O : X;
}

/* ------------------------------------- */

bool
TicTacToe::isValidMove(const int& move) const
{
  return move >= 0 && move < 9;
}

/* ------------------------------------- */

char&
TicTacToe::getCell(const int& move)
{
  return board[move];
}

/* ------------------------------------- */
  
TicTacToe::TicTacToe()
  : currentPlayer(Player::X)
{
  initializeBoard();
}

/* ------------------------------------- */

TicTacToe::TicTacToe(const TicTacToe& other)
  : currentPlayer(other.currentPlayer), nbMoves(other.nbMoves)
{
  for(int8_t i = 0; i < 9; ++i)
    board[i] = other.board[i];
}
/* ------------------------------------- */

void
TicTacToe::render() const
{
  using namespace std;

  cout << "   0   1   2" << endl;
  cout << "0  " << board[0] << " | " << board[1] << " | " << board[2] << endl;
  cout << "  ---+---+---" << endl;
  cout << "1  " << board[3] << " | " << board[4] << " | " << board[5] << endl;
  cout << "  ---+---+---" << endl;
  cout << "2  " << board[6] << " | " << board[7] << " | " << board[8] << endl;
  cout << endl;
}

/* ------------------------------------- */

bool
TicTacToe::play(const int& move)
{
  if (!isValidMove(move)) {
    return false;
  }

  char& cell = getCell(move);
  if (cell != ' ') {
    return false;
  }

  cell = currentPlayer;
  ++nbMoves;
  switchPlayer();

  return true;
}

/* ------------------------------------- */

void
TicTacToe::restart()
{
  initializeBoard();
}

/* ------------------------------------- */

TicTacToe::State
TicTacToe::checkWin() const
{
  State winner = DRAW;

  // check rows
  for (int i = 0; i < 9; i += 3) {
    if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i+2]) {
      winner = board[i] == X ? X_WON : O_WON;
    }
  }

  // check columns
  for (int i = 0; i < 3; ++i) {
    if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i+6]) {
      winner = board[i] == X ? X_WON : O_WON;
    }
  }

  // check diagonals
  if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
    winner = board[0] == X ? X_WON : O_WON;
  }

  if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
    winner = board[2] == X ? X_WON : O_WON;
  }

  if(winner != DRAW) {
    return winner;
  }

  return (nbMoves == 9) ? DRAW : CONTINUE;
}
