#include "test_pieces.h"
#include <bitset>
#include <cassert>
#include <iostream>

/* Testing collections of pieces that have being OR'd together 
START */
void test_all_pieces ( const std::string &pieces ){
    std::string all_pieces = "1111111111111111000000000000000000000000000000001111111111111111";
    assert ( all_pieces == pieces );
    std::cout << "boards.AllPieces: Pass" << std::endl;
}

void test_all_white_pieces ( const std::string &pieces ){
    std::string white_pieces = "0000000000000000000000000000000000000000000000001111111111111111";
    assert ( white_pieces == pieces );
    std::cout << "boards.WhitePieces: Pass" << std::endl;
}

void test_all_black_pieces ( const std::string &pieces ){
    std::string black_pieces = "1111111111111111000000000000000000000000000000000000000000000000";
    assert ( black_pieces == pieces );
    std::cout << "boards.BlackPieces: Pass" << std::endl;
}
/* Testing collections of pieces that have being OR'd together 
END */

/* Testing white pieces
START */
void test_white_pawns ( const std::string &pieces ){
    std::string test_pieces = "0000000000000000000000000000000000000000000000001111111100000000";
    assert ( test_pieces == pieces );
    std::cout << "boards.WhitePawns: Pass" << std::endl;
}

void test_white_rooks ( const std::string &pieces ){
    std::string test_pieces = "0000000000000000000000000000000000000000000000000000000010000001";
    assert ( test_pieces == pieces );
    std::cout << "boards.WhiteRooks: Pass" << std::endl;
}

std::string piece_to_string ( const BitBoard bb ){
    std::bitset<64> bb_bset ( bb );
    std::string str_bb = bb_bset.to_string();
    return str_bb;
}

void run_piece_tests ( const Boards boards ){
    test_all_pieces ( piece_to_string ( boards.AllPieces ));
    test_all_white_pieces ( piece_to_string ( boards.WhitePieces ));
    test_all_black_pieces ( piece_to_string ( boards.BlackPieces ));
    test_white_pawns ( piece_to_string ( boards.WhitePawns ));
    test_white_rooks ( piece_to_string ( boards.WhiteRooks ));
}
