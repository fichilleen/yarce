#include "identify_piece.h"
#include <stdlib.h> // For atoi
#include <iostream>

IdentifyPiece::IdentifyPiece(){
    file_map["A"] = file_a;
    file_map["B"] = file_b;
}

void IdentifyPiece::print_piece ( std::string which_file, std::string which_rank ){
    std::cout << which_file << std::endl ;
}
