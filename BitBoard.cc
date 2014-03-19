#include <bitset>
#include <iostream>
#include <string>

#include "BitBoard.h"
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
    board.white_pieces = board.white_pawns | board.white_knights | board.white_rooks | \
                    board.white_bishops | board.white_queens | board.white_king ;
    board.black_pieces = board.black_pawns | board.black_knights | board.black_rooks | \
                    board.black_bishops | board.black_queens | board.black_king ;
    board.all_pieces = board.white_pieces | board.black_pieces ;
}

void draw_board ( BitBoard &board ){
    std::bitset<64> board_representation ( board );
    for ( int i=0; i <= 63 ; ++i ){
        std::cout << board_representation [i] ;
        if (( (i+1) % 8) == 0 ) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main (){
    Boards boards ;
    apply_initial_positions ( boards );

    //draw_board ( boards.all_pieces );
    run_piece_tests ( boards );

    return 0;
}

