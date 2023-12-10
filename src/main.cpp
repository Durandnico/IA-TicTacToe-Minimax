#include "Tictactoe.h"
#include "minimax.h"
#include <iostream>
#include <limits>

int main() {
  
  TicTacToe game;

  game.render();
  while (game.checkWin() == TicTacToe::State::CONTINUE) {
    
    int row, col;

    std::cout << "\nwhich row would you like to play ?\n\t";
    std::cin >> row;

    std::cout << "\nwhich column would you like to play ?\n\t";
    std::cin >> col;

    if (!game.play(row, col)) {
    
      std::cout << "Invalid move" << std::endl;

      //clear buffer
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     

    } else {
      
      /* clear terminal */
      system("clear");
      
      if(game.getNbMoves() < 9)
        game.play(bestMove(game));      
      
      game.render();
    }


  }

  switch (game.checkWin())
  {
  case TicTacToe::State::X_WON:
    std::cout << "\n\nX WON !\n";
    break;
  
  case TicTacToe::State::O_WON:
    std::cout << "\n\nO WON !\n";
    break;

  default:
    std::cout << "\n\nIt is a draw !\n";
    break;
  }

  return 0;
}
