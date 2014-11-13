#include "identify_piece.h"
#include <stdlib.h> // For atoi
#include <iostream>

IdentifyPiece::IdentifyPiece(){}

void IdentifyPiece::print_piece ( char which_file, char which_rank ){
    // Not really sure about this method. Was thinking about using it for
    // debugging, but I can't think of a nice way for it to print the name of
    // the piece
    BitBoard *rank = file_rank_lookup [ which_rank ];
    BitBoard *file = file_rank_lookup [ which_file ];
    BitBoard on_position = *rank & *file;

    for ( std::vector<BitBoard*>::iterator i = bitboard_vector.begin() ; i != bitboard_vector.end(); ++i ){
        if ( **i & on_position ){
            std::cout << "IdentifyPiece::print_piece piece:: " << *i << std::endl;
            break;
        }
    }
}

BitBoard* IdentifyPiece::return_piece ( char which_file, char which_rank ){
    BitBoard *rank = file_rank_lookup [ which_rank ];
    BitBoard *file = file_rank_lookup [ which_file ];
    BitBoard on_position = *rank & *file;

    for ( std::vector<BitBoard*>::iterator i = bitboard_vector.begin() ; i != bitboard_vector.end(); ++i ){
        if ( **i & on_position ){
            return *i;
        }
    }
    // Return a blank board if we can't find anything
    std::cout << "IdentifyPiece::return_piece: Didn't find a match" << std::endl;
    return bitboard_vector[0];
}

BitBoard IdentifyPiece::show_square ( char which_file, char which_rank ){
    BitBoard *rank = file_rank_lookup [ which_rank ];
    BitBoard *file = file_rank_lookup [ which_file ];
    return *rank & *file;

}
