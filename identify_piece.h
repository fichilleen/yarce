#include "types.h"
#include <map>
#include <string>

#ifndef YARCE_IDENT_H
#define YARCE_IDENT_H

class IdentifyPiece{
public:
    IdentifyPiece ();
    void print_piece ( char which_file, char which_rank );
    BitBoard* return_piece ( char which_file, char which_rank );
    BitBoard show_square ( char which_file, char which_rank );
};

#endif 
