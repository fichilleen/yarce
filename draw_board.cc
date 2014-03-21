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
