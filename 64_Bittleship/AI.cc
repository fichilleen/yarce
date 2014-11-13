#include "AI.h"
#include "utils.h"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

AI::AI( std::string &name ){
    // Setup ships
    this->ai_ship = new Ships();
    // Explicitly set hit direction to 0
    this->hit_direction = 0;
    this->instance_name = name;
}

void AI::rand_chars ( char &rank, char &file ){

    // Do a check on random squares generated, to make sure we haven't
    // fired at them in the past
    bool have_not_fired_at = false;
    BitBoard tmpship, previous_fired_at;
    previous_fired_at = this->missed | this->hit | this->sank;

    while ( have_not_fired_at == false ){
        srand (time ( NULL ));
        rank = rand () % 8 + '1';
        file = rand () % 8 + 'A';
        intersect_file_rank ( tmpship, rank, file );
        if (!(tmpship &= previous_fired_at)){
            have_not_fired_at = true;
        }
    }
    assert (( file <= 'H' ) && ( file >= 'A' ));
    assert (( rank <= '8' ) && ( rank >= '1' ));
}

bool AI::check_perimeter ( char &s_rank, char &s_file, char &t_rank, char &t_file, int ship_length ){
    // Used for setting up ships, and selecting an adjacent square to fire at,
    // after getting a hit on a random square

    bool north_free = ((s_rank + ship_length) <= '8');
    bool south_free = ((s_rank - ship_length) >= '1');
    bool east_free = ((s_file + ship_length) <= 'H');
    bool west_free = ((s_file - ship_length) >= 'A');

    if (!(north_free) && !(south_free) && !(east_free) && !(west_free))
        return false;

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
        else if (west_free) {
            t_rank = s_rank;
            t_file = s_file;
            s_file = s_file - ship_length;
        }
        else if (north_free) {
            t_rank = s_rank + ship_length;
            t_file = s_file;
        }
        else{ // East
            t_file = s_file + ship_length;
            t_rank = s_rank;
        }
    }
    return true;
}

int AI::fire_on_last_hit ( Ships& enemy_ships, char &rank, char &file ){
    BitBoard fire_square;
    int shot_result;

    if ( this->hit_direction ){
        fire_square = this->confirmed_hit[1];
        direction_shift ( fire_square, this->hit_direction );
        board_to_char ( fire_square, file, rank );
    }
    else {
        bool have_not_fired_at = false;
        BitBoard tmpship, previous_fired_at;
        previous_fired_at = this->missed | this->hit | this->sank;

        while ( have_not_fired_at == false ){
            board_to_char ( this->confirmed_hit[0], file, rank );
            std::cout << "F/R:" << file << "/" << rank << std::endl;
            draw_board ( this->confirmed_hit[0], 0, 0, 0 );
            check_perimeter ( rank, file, rank, file, 1 );
            intersect_file_rank ( tmpship, rank, file );
            if (!(tmpship &= previous_fired_at)){
                have_not_fired_at = true;
            }
        }
    }
    shot_result = enemy_ships.fire_at ( file, rank );
    return shot_result;
}

int AI::take_turn ( Ships& enemy_ships ){
    int shot_result;
    char rank, file;
    if ( this->last_was_hit ){
        shot_result = this->fire_on_last_hit ( enemy_ships, rank, file );
    }
    else {
        this->rand_chars ( rank, file );
        shot_result = enemy_ships.fire_at ( file, rank );
    }

    switch ( shot_result ){
        case HIT:
            if (( ! this->last_was_hit ) && ( ! this->confirmed_hit[0] )){
                intersect_file_rank ( this->confirmed_hit[0], rank, file );
            }
            intersect_file_rank ( this->confirmed_hit[1], rank, file );
            this->last_was_hit = true;
            break;

        case SANK:
            // because this is the basis for a followup shot on a ship, set to
            // false so we're taking a fresh shot next time
            this->confirmed_hit[0] = 0ULL;
            this->confirmed_hit[1] = 0ULL;
            this->last_was_hit = false;
            break;

        case MISSED:
            break;

        case ALL_SANK:
            // cool!
            break;
    }
    // Update our records after firing
    enemy_ships.public_view ( this->hit, this->missed, this->sank );
    return shot_result;
}

void AI::setup_ships (){
    int ship_length = 5;
    int which_ship = 0;
    char s_file, s_rank, t_file, t_rank;
    //BitBoard hit, missed, placed, sank;

    while ( ship_length > 1 ){
        bool ship_valid = false;
        while ( ship_valid == false ){
            this->rand_chars ( s_rank, s_file );
            if (!check_perimeter ( s_rank, s_file, t_rank, t_file, ship_length ))
                continue;
            ship_valid = this->ai_ship->add_ship ( which_ship, s_file, s_rank, t_file, t_rank, false );
        }
        // Debugging
        //this->ai_ship->private_view ( hit, missed, sank, placed );
        //draw_board ( hit, missed, placed, sank );
        --ship_length;
        ++which_ship;
    }
}
