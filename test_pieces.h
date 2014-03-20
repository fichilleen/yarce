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
