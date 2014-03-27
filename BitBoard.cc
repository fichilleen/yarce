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

#include <bitset>
#include <iostream>
#include <string>

#include "BitBoard.h"
#include "draw_board.h"
#include "shift_test.h"
#include "test_pieces.h"


void apply_initial_positions ( Boards &board ){
    board.white_pawns    = 0x000000000000ff00;
    board.white_knights  = 0x0000000000000042;
    board.white_rooks    = 0x0000000000000081;
    board.white_bishops  = 0x0000000000000024;
    board.white_queens   = 0x0000000000000010;
    board.white_king     = 0x0000000000000008;
    //
    board.black_pawns    = 0x00ff000000000000;
    board.black_knights  = 0x4200000000000000;
    board.black_rooks    = 0x8100000000000000;
    board.black_bishops  = 0x2400000000000000;
    board.black_queens   = 0x1000000000000000;
    board.black_king     = 0x0800000000000000;
    //
}

void update_boards ( Boards &board ){
    board.white_pieces = board.white_pawns | board.white_knights | board.white_rooks | \
                    board.white_bishops | board.white_queens | board.white_king ;
    board.black_pieces = board.black_pawns | board.black_knights | board.black_rooks | \
                    board.black_bishops | board.black_queens | board.black_king ;
    board.all_pieces = board.white_pieces | board.black_pieces ;
}


int main (){
    Boards boards ;
    apply_initial_positions ( boards );
    update_boards ( boards );
    run_piece_tests ( boards );

    /* Test board. Playing about with movements and stuff */
    Boards test_board;
    test_board.white_queens = 0x0000000800000000;
    std::cout << "Starting:" << std::endl;
    draw_board ( test_board.white_queens );

    direction_shift ( test_board.white_queens, 1 );
    draw_board ( test_board.white_queens );

    direction_shift ( test_board.white_queens, 8 );
    draw_board ( test_board.white_queens );

    direction_shift ( test_board.white_queens, -8 );
    draw_board ( test_board.white_queens );

    return 0;
}

