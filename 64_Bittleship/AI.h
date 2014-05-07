#include "../types.h"
#include "../shift_test.h"
#include "Ships.h"

class AI {

    BitBoard confirmed_hit[5];
    BitBoard misses;
    BitBoard sank;
    int hit_direction;
    Ships *ai_ship;

    void setup_ships ();
    void rand_chars ( char &rank, char &file );

    public:
        AI();
        void take_turn ( Ships& enemy_ships );
};
