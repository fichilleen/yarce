#include "../types.h"

#ifndef BITTLESHIP_H
#define BITTLESHIP_H

enum ret_code { MISSED, HIT, SANK, ALL_SANK };

class Ships{

    BitBoard player_ships [4];
    // Backup of player_ships, used because when a ship is hit, we delete the
    // bit that was hit. This way we can compare to the original ship to show
    // if it was sank
    BitBoard original_ships [4]; 

    // meta ships
    BitBoard all_ships;
    BitBoard hit;
    BitBoard missed;
    BitBoard ships_sank;
    BitBoard temp_ship;

    void update_metaship ();
    void set_ship_bits ( const int &ship, const char &file, const char &rank );

public:
    Ships();
    int fire_at ( const char &file, const char &rank );
    bool add_ship ( const int &ship, const char &start_file, const char &start_rank, const char &to_file, const char &to_rank, bool err );
    void public_view ( BitBoard &hit, BitBoard &missed, BitBoard &sank );
    void private_view ( BitBoard &hit, BitBoard &missed, BitBoard &sank, BitBoard &placed );
};

#endif
