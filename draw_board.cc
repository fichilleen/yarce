/*  This file is part of yarce.

    yarce is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    yarce is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with yarce.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "draw_board.h"
#include <bitset>
#include <iostream>

void draw_board ( const BitBoard &board ){
    std::bitset<64> board_representation ( board );
    for ( int i=63; i >= 0 ; --i ){
        std::cout << board_representation [i] ;
        if (( i % 8) == 0 ) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

const std::string pretty(BitBoard b) {
    // This is pretty much copied verbatim from stockfish
    // I just changed the variables so they match my stuff

  std::string s = "+---+---+---+---+---+---+---+---+\n";

  for (int rank = 8; rank >= 0; --rank)
  {
      for (char file = 'A'; file <= 'H'; ++file)
          s.append(b & (file | rank) ? "| X " : "|   ");

      s.append("|\n+---+---+---+---+---+---+---+---+\n");
  }

  return s;
}

