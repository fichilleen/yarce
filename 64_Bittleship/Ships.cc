#include "Ships.h"
#include "utils.h"
#include <iostream>

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
        this->player_ships[2] |
        this->player_ships[3] ;
}

void Ships::set_ship_bits ( const int &ship, const char &file, const char &rank ){
    // Backend for setting up ships. Takes parameters from add_ship 
    BitBoard tmp_board;
    intersect_file_rank ( tmp_board, file, rank );
    this->player_ships[ship] |= tmp_board;
    this->original_ships[ship] = this->player_ships[ship];
    this->update_metaship();
}

bool Ships::add_ship ( const int &ship, const char &start_file, const char &start_rank, const char &to_file, const char &to_rank, bool err ){
    // Making sure the ship is the correct length is left to the client

    BitBoard lookup;
    // Make a temporary ship then merge it with the real target ship. This
    // allows us to make sure we don't collide with an already placed ship,
    // without the cost of iterating twice
    if ( start_file == to_file ){
        if ( start_rank == to_rank ){
            std::cout << "Error: No range specified" << std::endl;
            return false;
        }

        /* Iterating over this twice is kind of nasty.
         * TODO: Think of a better way to check if any of these squares are
         * taken before setting them */

        for (char i=start_rank; i<=to_rank; ++i){
            intersect_file_rank ( lookup, start_file, i );
            if ( lookup & this->all_ships ){
                if ( err ){
                    std::cout << "Error: Ship would itersect another on " << start_file << i << std::endl;
                }
                return false;
            }
        }
        for (char i=start_rank; i<=to_rank; ++i){
            this->set_ship_bits ( ship, start_file, i );
        }
    }
    else{
        for (char i=start_rank; i<=to_rank; ++i){
            intersect_file_rank ( lookup, i, start_rank );
            if ( lookup & this->all_ships ){
                if ( err ){
                    std::cout << "Error: Ship would itersect another on " << i << start_rank << std::endl;
                }
                return false;
            }
        }
        for (char i=start_file; i<=to_file; ++i){
            this->set_ship_bits ( ship, i, to_rank );
        }
    }
    return true;
}

int Ships::fire_at ( const char &file, const char &rank ){

    // Take file/rank (eg. A/1), get corresponding square
    BitBoard hit_square;
    intersect_file_rank ( hit_square, file, rank );

    if ((hit_square & this->missed ) || (hit_square & this->hit)){
        std::cout << "You can't fire at a position fired at previously" << std::endl;
        return -1;
    }

    std::cout << "Fire at " << file << rank << ": ";

    if ( ! ( hit_square & this->all_ships ) ){
        // Add missed square to bitboard of squares missed
        this->missed |= hit_square;
        this->update_metaship();
        std::cout << "Missed." << std::endl;
        return MISSED;
    }

    for (int i=0; i < 4 ; ++i){
        if ( this->player_ships [i] & hit_square ){
            // XOR ship. If there's an intersection, the ship was hit
            this->player_ships[i] ^= hit_square ;

            // Add hit square to bitboard of square hit
            this->hit |= hit_square;
            this->update_metaship();

            if ( this->all_ships == 0 ){
                std::cout << "All Sank" << std::endl;
                return ALL_SANK;
            }

            if ( this->player_ships[i] == 0 ){
                std::cout << "Sank." << std::endl;
                this->ships_sank |= this->original_ships[i];
                return SANK;
            }

            std::cout << "Hit." << std::endl;
            return HIT;
        }
    }
    return 9; // Debugging. Shouldn't hit this
}

void Ships::private_view ( BitBoard &hit, BitBoard &missed, BitBoard &sank, BitBoard &placed ){
    // Show user's ships, and attacks, both hit and miss by enemy player
    hit = this->hit;
    missed = this->missed;
    placed = this->all_ships;
    sank = this->ships_sank;
}

void Ships::public_view ( BitBoard &hit, BitBoard &missed, BitBoard &sank ){
    // Show known hits and misses on enemy
    hit = this->hit;
    missed = this->missed;
    sank = this->ships_sank;
}
