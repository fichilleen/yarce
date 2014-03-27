#include "types.h"
#include <map>
#include <string>

#ifndef YARCE_IDENT_H
#define YARCE_IDENT_H

class IdentifyPiece{
public:
    IdentifyPiece ();
    void print_piece ( std::string which_file, std::string which_rank );
    BitBoard* return_piece ( std::string which_file, std::string which_rank );
    BitBoard show_square ( std::string which_file, std::string which_rank );
};

#endif 
