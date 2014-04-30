#include "../types.h"

#ifndef BITTLESHIP_H
#define BITTLESHIP_H

enum ret_code { MISSED, HIT, SANK, ALL_SANK };

class Ships{

    BitBoard player_ships [3];

    BitBoard all_ships;
    BitBoard missed;
    BitBoard hit;

    // add_ship should be private. Public for now, to assist hardcoding AI's
    // ship
    //bool add_ship ( BitBoard &ship, const char &file, const char &rank );

    void update_metaship ();

public:
    Ships();
    void setup_ships ();
    int fire_at ( const char &file, const char &rank );
    bool add_ship ( const int &ship, const char &file, const char &rank );
    void public_view ( BitBoard &view );
    void private_view ( BitBoard &hit, BitBoard &missed, BitBoard &placed );
};

#endif
