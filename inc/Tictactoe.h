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

#pragma once
#include <array>
#include <cstdint>


/*! 
 *  \file Tictactoe.h
 *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 05 December 2023 - 15:20:13
 *
 *  \brief 
 *
 *
 */

class TicTacToe
{
private:
  /* enum */
  enum Player {X='X', O='O'};
  
  /* variables */
  char board[9];
  Player currentPlayer;
  int nbMoves;

  /* methodes */  
  /*!
   *  \fn void initializeBoard()
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:32:17
   *  \brief initialize the board with empty cells
   *  \remarks --
   */
  void initializeBoard();

  /*!
   *  \fn bool isValidMove(int move)
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:39:56
   *  \brief check if the move is valid
   *  \param move:  the move to check
   *  \return true if the move is valid, false otherwise
   *  \remarks --
   */
  bool isValidMove(const int& move) const;
  
  /*!
   *  \fn char& getCell(int move)
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:42:02
   *  \brief get the cell corresponding to the move
   *  \param move:  the move
   *  \return the cell corresponding to the move
   *  \remarks --
   */
  char& getCell(const int& move);

public:
  /* variables */
  enum State {CONTINUE = 2, DRAW = 0, X_WON = 1, O_WON = -1};

  /* constructor */
  TicTacToe();

  TicTacToe(const TicTacToe&);

  /* methodes */
  /*!
   *  \fn void render()
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:33:49
   *  \brief render the board
   *  \remarks --
   */
  void render() const;

  /*!
   *  \fn bool play()
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:34:08
   *  \brief play a move
   *  \param move:  the move to play
   *  \return false if the move is invalid, true otherwise
   *  \remarks --
   */
  bool play(const int& move);

  bool play(const int& row, const int& col)
  {
    return play(row * 3 + col);
  }

  /*!
   *  \fn void restart()
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:34:08
   *  \brief restart the game
   *  \remarks --
   */
  void restart();

  /*!
   *  \fn State checkWin() const
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:34:08
   *  \brief check the state of the game
   *  \return the state of the game (CONTINUE, DRAW, X_WON, O_WON)
   *  \remarks --
   */
  State checkWin() const;

    /*!
   *  \fn void switchPlayer()
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 00:32:17
   *  \brief change the current player
   *  \remarks --
   */
  void switchPlayer();


  /*!
   *  \fn char[9] getArr()
   *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
   *  \version 0.1
   *  \date Tue 05 December 2023 - 16:06:44
   *  \brief 
   *  \param 
   *  \return 
   *  \remarks 
   */
  char* getArr() {
    return board;
  }

  const char* getArr() const {
    return board;
  }

  char getCurrentPlayer() const
  {
    return currentPlayer;
  }

  int8_t getNbMoves() const
  {
    return nbMoves;
  }

  void incrementeMoves()
  {
    ++nbMoves;
  }

  void decreaseMoves()
  {
    --nbMoves;
  }
};