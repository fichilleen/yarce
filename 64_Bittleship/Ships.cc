#include "Ships.h"
#include <iostream>

using namespace std;


Ships::Ships(){
    init_lookups();
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

    this->player_ships[ship] |= (*file_rank_lookup[file] & *file_rank_lookup[rank]);
    this->update_metaship();
    return true;
}

int Ships::fire_at ( const char &file, const char &rank ){

    // Take file/rank (eg. A/1), get corresponding square
    BitBoard hit_square = ( *file_rank_lookup[file] & *file_rank_lookup[rank] );

    if ( ! ( hit_square & this->all_ships ) ){
        // Add missed square to bitboard of squares missed
        this->missed |= hit_square;
        this->update_metaship();
        return MISSED;
    }

    for ( int i=0; i < 3 ; ++i){
        if ( this->player_ships [i] & hit_square ){
            // XOR ship. If there's an intersection, the ship was hit
            this->player_ships[i] ^= hit_square ;

            // Add hit square to bitboard of square hit
            this->hit |= hit_square;
            this->update_metaship();

            if ( this->all_ships == 0 )
                return ALL_SANK;

            if ( this->player_ships[i] == 0 )
                return SANK;

            return HIT;
        }
    }
    return 9; // Debugging. Shouldn't hit this
}

void Ships::private_view ( BitBoard &hit, BitBoard &missed, BitBoard &placed ){
    hit = this->hit;
    missed = this->missed;
    placed = this->all_ships;
}

