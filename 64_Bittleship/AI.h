#include "../types.h"
#include "../shift_test.h"
#include "Ships.h"
#include <string>

class AI {

    BitBoard confirmed_hit[2];
    BitBoard hit;
    BitBoard missed;
    BitBoard sank;
    int hit_direction;
    bool last_was_hit;

    void rand_chars ( char &rank, char &file );
    bool check_perimeter ( char &s_rank, char &s_file, char &t_rank, char &t_file, int ship_length );
    int fire_on_last_hit ( Ships& enemy_ships, char &rank, char &file );

    public:
        Ships *ai_ship;
        std::string instance_name;
        AI( std::string &name );
        int take_turn ( Ships& enemy_ships );
        void setup_ships ();
};
