#include "Ships.h"
#include <iostream>
#include <string>

void draw_board ( const BitBoard &hit, const BitBoard &missed, const BitBoard &placed ){
    std::cout << "X: Hit -- M: Missed -- O -- Placed" << std::endl;
    std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
    for (char rank = '8'; rank >= '1'; --rank) {
        for (char file = 'A'; file <= 'H'; ++file) {

            if ( hit & ( *file_rank_lookup[file] & *file_rank_lookup[rank] )){
                std::cout << "| X ";
                continue;
            }
            if ( missed & ( *file_rank_lookup[file] & *file_rank_lookup[rank] )){
                std::cout << "| M ";
                continue;
            }
            if ( placed & ( *file_rank_lookup[file] & *file_rank_lookup[rank] )){
                std::cout << "||||";
                continue;
            }
            std::cout << "|   ";
        }
        std::cout << "|\n+---+---+---+---+---+---+---+---+" << std::endl;
    }
}


int main (){

    Ships *test_ship = new Ships();

    test_ship->add_ship ( 0, 'A', '1' );
    test_ship->add_ship ( 0, 'A', '2' );
    test_ship->add_ship ( 0, 'A', '3' );
    test_ship->add_ship ( 0, 'A', '4' );

    test_ship->add_ship ( 1, 'E', '5' );
    test_ship->add_ship ( 1, 'F', '5' );
    test_ship->add_ship ( 1, 'G', '5' );

    test_ship->add_ship ( 2, 'D', '2' );
    test_ship->add_ship ( 2, 'E', '2' );

    BitBoard hit, missed, placed;
    test_ship->private_view ( hit, missed, placed );
    draw_board ( hit, missed, placed );

    int ret;
    ret = test_ship->fire_at ( 'A', '2' );
    std::cout << "Fire at A2: " << ret << std::endl;
    ret = test_ship->fire_at ( 'B', '7' );
    std::cout << "Fire at B7: " << ret << std::endl;

    test_ship->private_view ( hit, missed, placed );
    draw_board ( hit, missed, placed );

    return 0;
}
