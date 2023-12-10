/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Tictactoe minimax                                  :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 05/December/2023 by Durandnico      #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file minimax.cpp
 *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 05 December 2023 - 02:02:11
 *
 *  \brief 
 *
 *
 */

// Inclusion des entetes de librairies
#include "../inc/minimax.h"
#include "../inc/Tictactoe.h"
#include <vector>
#include <cstdint>

int nbChecks;
int checks[10] = {0};

std::vector<int8_t>
getMoves(const TicTacToe& game)
{
  std::vector<int8_t> possibleMove;
  possibleMove.reserve(9 - game.getNbMoves());
 
  char const * board = game.getArr();
  for(int8_t i = 0; i < 9; ++i)
    if(board[i] == ' ')
      possibleMove.emplace_back(i);

  return possibleMove;
}

int8_t
minimax(TicTacToe& game, int8_t depth, bool isMaxPlayer)
{ 
  /* first check is terminal state */
  TicTacToe::State win = game.checkWin();
  if(win != TicTacToe::CONTINUE)
  {
    checks[0]++;
    return (int8_t) win;
  }
    
    
    
  /* init all variable that we'll use */
  int8_t result;
  std::vector<int8_t> possibleMove = getMoves(game);
  char* const board = game.getArr();
  const char player = game.getCurrentPlayer();
  
  /* change variable for next iteration*/
  game.switchPlayer();
  game.incrementeMoves();
  ++depth;

  // Max player : X
  if(isMaxPlayer)
  {
    result = -2;
    for(int8_t& move : possibleMove)
    {
      board[move] = player;
      result = MAX(result, minimax(game, depth, false));
      board[move] = ' ';
    }
  }

  // Min player : O
  else
  {
    result = 2;
    for(int8_t& move : possibleMove)
    {
      board[move] = player;
      result = MIN(result, minimax(game, depth, true));
      board[move] = ' ';
    } 
  }

  /* return var as same as we got them */  
  game.decreaseMoves();
  game.switchPlayer();
  return result;
}


int8_t
bestMove(TicTacToe& game)
{
  nbChecks = 0;
  int8_t bestMove = -1;
  int8_t moveScore;

  std::vector<int8_t> possibleMove = getMoves(game);
  const char player = game.getCurrentPlayer();
  const bool isMaxPlayer = player == 'X';
  char* const board = game.getArr();

  game.switchPlayer();
  game.incrementeMoves();
  if(isMaxPlayer)
  {
    moveScore = -8;
    for(const int8_t& move : possibleMove)
    {
      board[move] = player;
      int tmp = minimax(game, 0, false);
      board[move] = ' ';
      if(tmp > moveScore) 
      {
        moveScore = tmp;
        bestMove = move; 
      }
    }
  }


  else 
  {
    moveScore = 8;
    for(const int8_t& move : possibleMove)
    {
      board[move] = player;
      int8_t tmp = minimax(game, 0, true);
      nbChecks = 0;
      board[move] = ' ';
      if(tmp < moveScore)
      {
        moveScore = tmp;
        bestMove = move; 
      }
    }
  }
  
   
  game.decreaseMoves();
  game.switchPlayer();
  return bestMove;
}