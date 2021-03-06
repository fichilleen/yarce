/*  This file is part of yarce.

    yarce is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    yarce is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with yarce.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "test_pieces.h"
#include "identify_piece.h"
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

void test_white_knights ( const string &pieces ){
    string test_pieces = "0000000000000000000000000000000000000000000000000000000001000010";
    make_assertation ( "boards.white_knights", test_pieces, pieces );
}

void test_white_bishops ( const string &pieces ){
    string test_pieces = "0000000000000000000000000000000000000000000000000000000000100100";
    make_assertation ( "boards.white_bishops", test_pieces, pieces );
}

void test_white_queens ( const string &pieces ){
    string test_pieces = "0000000000000000000000000000000000000000000000000000000000010000";
    make_assertation ( "boards.white_queens", test_pieces, pieces );
}

void test_white_king ( const string &pieces ){
    string test_pieces = "0000000000000000000000000000000000000000000000000000000000001000";
    make_assertation ( "boards.white_king", test_pieces, pieces );
}

/* Testing white pieces starting positions
END */

/* Testing black pieces starting positions
START */
void test_black_pawns ( const string &pieces ){
    string test_pieces = "0000000011111111000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_pawns", test_pieces, pieces );
}

void test_black_rooks ( const string &pieces ){
    string test_pieces = "1000000100000000000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_rooks", test_pieces, pieces );
}

void test_black_knights ( const string &pieces ){
    string test_pieces = "0100001000000000000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_knights", test_pieces, pieces );
}

void test_black_bishops ( const string &pieces ){
    string test_pieces = "0010010000000000000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_bishops", test_pieces, pieces );
}

void test_black_queens ( const string &pieces ){
    string test_pieces = "0001000000000000000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_queens", test_pieces, pieces );
}

void test_black_king ( const string &pieces ){
    string test_pieces = "0000100000000000000000000000000000000000000000000000000000000000";
    make_assertation ( "boards.black_king", test_pieces, pieces );
}

/* Misc tests */

void test_no_conflicting_pieces ( const Boards boards ){
    // Make sure no two pieces are placed on the same square. Useful at any
    // point of the execution
    const static unsigned long long test_pieces = 0;
    BitBoard and_pieces = \
        boards.white_pawns & boards.white_knights & boards.white_rooks & \
        boards.white_bishops & boards.white_queens & boards.white_king & \
        boards.black_pawns & boards.black_knights & boards.black_rooks & \
        boards.black_bishops & boards.black_queens & boards.black_king;
    assert ( and_pieces == test_pieces );
    std::cout.width ( 25 );
    std::cout << "No conflicting pieces" << std::left << ": Passed" << std::endl;
}

void make_assertation ( const string &testname, const string &exp, const string &actual ){
    // Just to keep the repetition of print, formatting and assertions in
    // other functions to a minimum
    assert ( exp == actual );
    // TODO: Why does the first instance of this get formatted incorrectly?
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

    /* Meta boards */
    piece_to_string ( str_piece, boards.all_pieces );
    test_all_pieces ( str_piece );

    piece_to_string ( str_piece, boards.white_pieces );
    test_all_white_pieces ( str_piece );

    piece_to_string ( str_piece, boards.black_pieces );
    test_all_black_pieces ( str_piece );

    /* White pieces */
    piece_to_string ( str_piece, boards.white_pawns );
    test_white_pawns ( str_piece );

    piece_to_string ( str_piece, boards.white_rooks );
    test_white_rooks ( str_piece );

    piece_to_string ( str_piece, boards.white_knights );
    test_white_knights ( str_piece );

    piece_to_string ( str_piece, boards.white_bishops );
    test_white_bishops ( str_piece );

    piece_to_string ( str_piece, boards.white_queens );
    test_white_queens ( str_piece );

    piece_to_string ( str_piece, boards.white_king );
    test_white_king ( str_piece );

    /* Black pieces */
    piece_to_string ( str_piece, boards.black_pawns );
    test_black_pawns ( str_piece );

    piece_to_string ( str_piece, boards.black_rooks );
    test_black_rooks ( str_piece );

    piece_to_string ( str_piece, boards.black_knights );
    test_black_knights ( str_piece );

    piece_to_string ( str_piece, boards.black_bishops );
    test_black_bishops ( str_piece );

    piece_to_string ( str_piece, boards.black_queens );
    test_black_queens ( str_piece );

    piece_to_string ( str_piece, boards.black_king );
    test_black_king ( str_piece );

    test_no_conflicting_pieces ( boards );

    /* Square identification */
    BitBoard* bb_pointer;
    IdentifyPiece *ident = new IdentifyPiece();

    bb_pointer = ident->return_piece ( 'H', '8' );
    assert ( *bb_pointer == boards.black_rooks );
    /*
    bb_pointer = ident->return_piece ( "E", "1" );
    assert ( *bb_pointer == boards.white_king );
    */

}

