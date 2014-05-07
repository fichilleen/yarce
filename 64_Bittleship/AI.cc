#include "AI.h"
#include <time.h>
#include <stdlib.h>

AI::AI(){
    // Setup ships
    this->ai_ship = new Ships();
    this->setup_ships();
}

void AI::rand_chars ( char &rank, char &file ){
    srand (time ( NULL ));
    rank = rand () % 8 + '1';
    file = rand () % 8 + 'A';
}

void AI::setup_ships (){
    int ship_length = 5;
    int which_ship = 0;
    char s_file, s_rank, t_file, t_rank, dummy;
    BitBoard hit, missed, placed, sank;

    // Mark if travel in these directions is available from selected square
    bool north_free, south_free, east_free, west_free;

    while ( ship_length > 1 ){
        bool ship_valid = false;
        int user_length = 0;
        while ( ship_valid == false ){
            this->rand_chars ( s_rank, s_file );

            north_free = ((s_file + ship_length) <= 'H');
            south_free = ((s_file - ship_length) >= 'A');
            east_free = ((s_rank + ship_length) <= '8');
            west_free = ((s_rank - ship_length) >= '1');

            // Psuedo-random weighting, just to make things slightly less
            // predictable, by not always trying to place directions in the
            // same order
            if (((ship_length % 2) == 0) && (north_free || east_free )){
                if (north_free){
                    t_rank = s_rank + ship_length;
                    t_file = s_file;
                }
                else{ // East
                    t_file = s_file + ship_length;
                    t_rank = s_rank;
                }
            }
            // Placing the ship forces start file/rank to be lower numbers
            // than to file/rank, so switch vars around and decrement for
            // south/west
            else{
                if (south_free){
                    t_rank = s_rank;
                    t_file = s_file;
                    s_rank = s_rank - ship_length;
                }
                else{ // West
                    t_rank = s_rank;
                    t_file = s_file;
                    s_file = s_file - ship_length;
                }
            }
            ship_valid = this->ai_ship->add_ship ( which_ship, s_file, s_rank, t_file, t_rank );
        }
        //player_ship.private_view ( hit, missed, placed, sank );
        //draw_board ( hit, missed, placed, sank );
        --ship_length;
        ++which_ship;
    }
}
