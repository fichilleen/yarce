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

#include "types.h"
#include <string>

void test_all_pieces ( const std::string &pieces );
void test_all_white_pieces ( const std::string &pieces );
void test_all_black_pieces ( const std::string &pieces );
// White pieces
void test_white_pawns ( const std::string &pieces );
void test_white_rooks ( const std::string &pieces );
void test_white_knights ( const std::string &pieces );
void test_white_bishops ( const std::string &pieces );
void test_white_queens ( const std::string &pieces );
void test_white_king ( const std::string &pieces );
// Black pieces
void test_black_pawns ( const std::string &pieces );
void test_black_rooks ( const std::string &pieces );
void test_black_knights ( const std::string &pieces );
void test_black_bishops ( const std::string &pieces );
void test_black_queens ( const std::string &pieces );
void test_black_king ( const std::string &pieces );

void test_no_conflicting_pieces ( const Boards boards );

void piece_to_string ( std::string &result, const BitBoard bb );
void run_piece_tests ( const Boards boards );
void make_assertation ( const std::string &testname, const std::string &exp, const std::string &actual );
