#include "test_pieces.h"
#include <bitset>
#include <cassert>
#include <iostream>

using std::string;

/* Testing collections of pieces that have being OR'd together 
START */
void test_all_pieces ( const string &pieces ){
    string all_pieces = "1111111111111111000000000000000000000000000000001111111111111111";
    make_assertation ( "boards.all_pieces", all_pieces, pieces );
}

void test_all_white_pieces ( const string &pieces ){
    string white_pieces = "0000000000000000000000000000000000000000000000001111111111111111";
    make_assertation ( "boards.white_pieces", white_pieces, pieces );
}

void test_all_black_pieces ( const string &pieces ){
    string test_pieces = "1111111111111111000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_pieces", test_pieces, pieces );
}
/* Testing collections of pieces that have being OR'd together 
END */

/* Testing white pieces starting positions
START */
void test_white_pawns ( const string &pieces ){
    string test_pieces = "0000000000000000000000000000000000000000000000001111111100000000";
    make_assertation ( "boards.white_pawns", test_pieces, pieces );
}

void test_white_rooks ( const string &pieces ){
    string test_pieces = "0000000000000000000000000000000000000000000000000000000010000001";
    make_assertation ( "boards.white_rooks", test_pieces, pieces );
}

/* Testing white pieces starting positions
END (once I add more tests) */

/* Misc tests */

void test_no_conflicting_pieces ( const Boards boards ){
    // Make sure no two pieces are placed on the same square. Useful at any
    // point of the execution
    const static string test_pieces = "0000000000000000000000000000000000000000000000000000000000000000";
    BitBoard and_pieces = \
        boards.white_pawns & boards.white_knights & boards.white_rooks & \
        boards.white_bishops & boards.white_queens & boards.white_king & \
        boards.black_pawns & boards.black_knights & boards.black_rooks & \
        boards.black_bishops & boards.black_queens & boards.black_king;
    string and_pieces_str;
    piece_to_string ( and_pieces_str, and_pieces );
    make_assertation ( "No conflicting pieces", and_pieces_str, test_pieces );
}

void make_assertation ( const string &testname, const string &exp, const string &actual ){
    // Just to keep the repetition of print, formatting and assertions in
    // other functions to a minimum
    assert ( exp == actual );
    std::cout.width ( 25 );
    std::cout << testname << std::left << ": Passed" << std::endl;
}

void piece_to_string ( string &result, const BitBoard bb ){
    // Convert bitboard (unsigned long long) to bitset, then to string for
    // comparison with string representations of how the board should look
    std::bitset<64> bb_bset ( bb );
    result = bb_bset.to_string();
}

void run_piece_tests ( const Boards boards ){
    string str_piece;

    std::cout << "################################################################################" << std::endl;
    std::cout << "# Running sanity tests" << std::endl;
    std::cout << "################################################################################" << std::endl;

    piece_to_string ( str_piece, boards.all_pieces );
    test_all_pieces ( str_piece );

    piece_to_string ( str_piece, boards.white_pieces );
    test_all_white_pieces ( str_piece );

    piece_to_string ( str_piece, boards.black_pieces );
    test_all_black_pieces ( str_piece );

    piece_to_string ( str_piece, boards.white_pawns );
    test_white_pawns ( str_piece );

    piece_to_string ( str_piece, boards.white_rooks );
    test_white_rooks ( str_piece );

    test_no_conflicting_pieces ( boards );
}
