#include "AI.h"
#include "Ships.h"
#include "utils.h"
#include <iostream>
#include <string>

char get_file (){
    char file;
    bool valid_input = false;
    while ( valid_input == false ){
        std::cout << "Enter File (A-H, in uppercase): ";
        std::cin >> file;
        if (( file < 'A' ) || (file > 'H' )){
            std::cout << "Error. Not a valid file (must be A-H)" << std::endl;
        }
        else valid_input = true;
    }
    return file;
}

char get_rank (){
    char rank;
    bool valid_input = false;
    while ( valid_input == false ){
        std::cout << "Enter Rank (1-8): ";
        std::cin >> rank;
        if (( rank < '1' ) || (rank > '8' )){
            std::cout << "Error. Not a valid rank (must be 1-8)" << std::endl;
        }
        else valid_input = true;
    }
    return rank;
}

void add_user_ships ( Ships &player_ship ){
    // Add four ships. Lengths 5,4,3,2
    int ship_length = 5;
    int which_ship = 0;
    char s_file, s_rank, t_file, t_rank;

    BitBoard hit, missed, placed, sank;

    while ( ship_length > 1 ){

        bool ship_valid = false;
        int user_length = 0;
        while ( ship_valid == false ){
            std::cout << "Ship of length " << ship_length << " start file:" << std::endl;
            s_file = get_file();
            std::cout << "Start rank:" << std::endl;
            s_rank = get_rank();

            std::cout << "End file:" << std::endl;
            t_file = get_file();
            std::cout << "End rank:" << std::endl;
            t_rank = get_rank();

            if ( s_rank == t_rank ){
                user_length = ( t_file - s_file ) + 1;
            }
            else{
                if ( s_file != t_file ){
                    std::cout << "Error: Ship must be in a straight line" << std::endl;
                    continue;
                }
                user_length = ( t_rank - s_rank ) + 1;
            }

            if ( user_length != ship_length ){
                std::cout << "Error: Length of ship must be " << ship_length << ". Specified length is " << user_length << std::endl;
                continue;
            }

            if ( ! (player_ship.add_ship ( which_ship, s_file, s_rank, t_file, t_rank, true ) )){
                continue;
            }
            else {
                ship_valid = true;
            }
        }
        player_ship.private_view ( hit, missed, placed, sank );
        draw_board ( hit, missed, placed, sank );
        --ship_length;
        ++which_ship;
    }
}


int handle_firing ( Ships &player_ship ){
    char file, rank;
    int fired = -1;

    while ( fired < 0 ){
        file = get_file();
        rank = get_rank();
        fired = player_ship.fire_at ( file, rank );
    }
    return fired;
}


int main (){

    //Ships *test_ship = new Ships();
    
    std::string name1, name2;
    name1 = "AI player 1";
    name2 = "AI player 2";
    AI *ai_player = new AI( name1 );
    ai_player->setup_ships();

    BitBoard hit = 0;
    BitBoard missed = 0;
    BitBoard placed = 0;
    BitBoard sank = 0;

    //add_user_ships ( *test_ship );

    //test_ship->public_view ( hit, missed, sank );
    //draw_board ( hit, missed, placed, sank );
    

    int fire_return = 0, fire_return2 = 0;
    AI *ai_player2 = new AI( name2 );
    ai_player2->setup_ships();

    while (( fire_return != ALL_SANK) && ( fire_return2 != ALL_SANK)){
        fire_return = ai_player->take_turn ( *ai_player2->ai_ship );
        ai_player2->ai_ship->public_view ( hit, missed, sank );
        draw_board ( hit, missed, placed, sank );

        fire_return2 = ai_player2->take_turn ( *ai_player->ai_ship );
        ai_player->ai_ship->public_view ( hit, missed, sank );
        draw_board ( hit, missed, placed, sank );
    }

    while ( fire_return != ALL_SANK ){
        fire_return = handle_firing ( *ai_player->ai_ship );
        ai_player->ai_ship->public_view ( hit, missed, sank );
        draw_board ( hit, missed, placed, sank );
    }
    /*
    while ( fire_return != ALL_SANK ){
        fire_return = handle_firing ( *test_ship );
        test_ship->public_view ( hit, missed, sank );
        draw_board ( hit, missed, placed, sank );
    }
    */

    std::cout << "All ships sank!" << std::endl;
    //test_ship->private_view ( hit, missed, sank, placed );
    //draw_board ( hit, missed, placed, sank );

    return 0;
}
