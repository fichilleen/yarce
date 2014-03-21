#include "shift_test.h"

#define SHIFT_EAST << 1

void king_shift ( BitBoard &king, direction shift_dir ){
    if ( shift_dir == EAST ){
        if ( ! (file_h & king)){
            king = king SHIFT_EAST;
        }
    }
}


