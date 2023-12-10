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

/*! 
 *  \file minimax.h
 *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
 *  \version 0.1
 *  \date Tue 05 December 2023 - 02:02:47
 *
 *  \brief 
 *
 *
 */

// Inclusion des entetes de librairies
#include <iostream>
#include <cstdint>
#include <vector>
#include "Tictactoe.h"

// Define
#define MIN(a,b) (a<b)? a : b
#define MAX(a,b) (a>b)? a : b

// constexpr
constexpr int MAX_DEPTH = 1000000000;

int8_t minimax(TicTacToe& game, int8_t depth, bool isMaxPlayer);

std::vector<int8_t> getMoves(const TicTacToe& game);

int8_t bestMove(TicTacToe& game);