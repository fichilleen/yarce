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

const std::string pretty( const BitBoard &b) {
    // This is copied pretty closely from a function in stockfish

  std::string s = "+---+---+---+---+---+---+---+---+\n";

  for (char rank = '8'; rank >= '1'; --rank)
  {
      for (char file = 'A'; file <= 'H'; ++file)
      {

          //std::cout << "File: " << *file_rank_lookup[file] << std::endl;
          //std::cout << "Rank: " << *file_rank_lookup[rank] << std::endl;

          s.append ( b & ( *file_rank_lookup[file] & *file_rank_lookup[rank] ) ? "| X " : "|   ");
      }
      s.append("|\n+---+---+---+---+---+---+---+---+\n");
  }

  return s;
}

