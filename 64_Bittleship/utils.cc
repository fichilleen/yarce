#include "utils.h"
#include <iostream>

void draw_board ( const BitBoard &hit, const BitBoard &missed, const BitBoard &placed, const BitBoard &sank ){
    std::cout << "X: Hit -- M: Missed -- O: Placed -- S: Sank" << std::endl;
    std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
    BitBoard lookup;
    for (char rank = '8'; rank >= '1'; --rank) {
        for (char file = 'A'; file <= 'H'; ++file) {
            lookup = *file_rank_lookup[file] & *file_rank_lookup[rank] ;

            if ( sank & lookup ){
                std::cout << "| S ";
                continue;
            }
            if ( hit & lookup ){
                std::cout << "| X ";
                continue;
            }
            if ( missed & lookup ){
                std::cout << "| M ";
                continue;
            }
            if ( placed & lookup ){
                std::cout << "| 0 ";
                continue;
            }
            std::cout << "| " << file << rank;
        }
        std::cout << "|\n+---+---+---+---+---+---+---+---+" << std::endl;
    }
}

void intersect_file_rank ( BitBoard &new_board, const char &file, const char &rank ){
    // Populate a bitboard with one bit, at the intersection of a rank and file
    new_board = *file_rank_lookup[file] & *file_rank_lookup[rank] ;
}

void board_to_char ( const BitBoard &board, char &file, char &rank ){
    // Take a bitboard, and get rank and file value for what square the piece
    // on it occupies. Obviously, this is intended for a board which only
    // represents one piece.
    for (rank = '8'; rank >= '1'; --rank) {
        if ( *file_rank_lookup[rank] & board ) 
            break;
    }
    for (file = 'A'; file <= 'H'; ++file) {
        if ( *file_rank_lookup[file] & board )
            break;
    }
}

