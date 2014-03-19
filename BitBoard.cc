#include <bitset>
#include <iostream>
#include <string>

#include "BitBoard.h"
#include "test_pieces.h"


void apply_initial_positions ( Boards &board ){
    board.WhitePawns    = 0x000000000000ff00;
    board.WhiteKnights  = 0x0000000000000042;
    board.WhiteRooks    = 0x0000000000000081;
    board.WhiteBishops  = 0x0000000000000024;
    board.WhiteQueens   = 0x0000000000000010;
    board.WhiteKing     = 0x0000000000000008;
    //
    board.BlackPawns    = 0x00ff000000000000;
    board.BlackKnights  = 0x4200000000000000;
    board.BlackRooks    = 0x8100000000000000;
    board.BlackBishops  = 0x2400000000000000;
    board.BlackQueens   = 0x1000000000000000;
    board.BlackKing     = 0x0800000000000000;
    //
    board.WhitePieces = board.WhitePawns | board.WhiteKnights | board.WhiteRooks | \
                    board.WhiteBishops | board.WhiteQueens | board.WhiteKing ;
    board.BlackPieces = board.BlackPawns | board.BlackKnights | board.BlackRooks | \
                    board.BlackBishops | board.BlackQueens | board.BlackKing ;
    board.AllPieces = board.WhitePieces | board.BlackPieces ;
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

    //draw_board ( boards.AllPieces );
    run_piece_tests ( boards );

    return 0;
}

