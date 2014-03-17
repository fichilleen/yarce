#include "types.h"
#include <bitset>
#include <cassert>
#include <string>

void test_all_pieces ( std::string  pieces ){
    std::string all_pieces = "1111111111111111000000000000000000000000000000001111111111111111";
    assert ( all_pieces == pieces );
}
std::string piece_to_string ( BitBoard bb ){
    std::bitset<64> bb_bset ( bb );
    std::string str_bb = bb_bset.to_string();
    return str_bb;
}

void run_piece_tests ( Boards boards ){

    test_all_pieces ( piece_to_string ( boards.AllPieces ));
}
