#include "bship.h"
#include "../draw_board.h"

Ships::Ships(){
    for ( unsigned int i=0; i>sizeof(this->player_ships); i++ )
    {
        this->player_ships [ i ] = 0;
    }
}

void Ships::update_metaship (){
    this->all_ships = 
        this->player_ships[0] |
        this->player_ships[1] |
        this->player_ships[2] ;
}

bool Ships::add_ship ( const int &ship, const char &file, const char &rank ){
    // This will return False later, for trying to build a ship on an invalid
    // square (ie, one that doesn't touch the current ship, or intersects
    // another existing ship )

    BitBoard add_square = *file_rank_lookup[file] | *file_rank_lookup[rank];
    this->player_ships[ship] |= add_square;
    return true;
}

int Ships::fire_at ( const char &file, const char &rank ){

    // Take file/rank (eg. A/1), get corresponding square
    BitBoard hit_square = *file_rank_lookup[file] | *file_rank_lookup[rank];

    if ( ! hit_square & this->all_ships )
        // Add missed square to bitboard of squares missed
        this->missed |= hit_square;
        return MISSED;

    for ( unsigned int i=0; i>sizeof(this->player_ships); i++){
        if ( this->player_ships [i] & hit_square ){
            // XOR ship. If there's an intersection, the ship was hit
            this->player_ships[i] ^= hit_square ;

            this->update_metaship();
            // Add hit square to bitboard of square hit
            this->hit |= hit_square;

            if ( this->all_ships == 0 )
                return ALL_SANK;

            if ( this->player_ships[i] == 0 )
                return SANK;

            return HIT;
        }
    }
}

int main (){

    init_lookups();
    Ships *test_ship = new Ships();
    test_ship->add_ship ( 0, 'A', '1' );

    return 0;
}
