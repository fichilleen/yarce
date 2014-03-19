#include "types.h"
#include <string>

void test_all_pieces ( const std::string &pieces );
void test_all_white_pieces ( const std::string &pieces );
void test_all_black_pieces ( const std::string &pieces );
void test_white_pawns ( const std::string &pieces );
void test_white_rooks ( const std::string &pieces );
void test_no_conflicting_pieces ( const Boards boards );

void piece_to_string ( std::string &result, const BitBoard bb );
void run_piece_tests ( const Boards boards );
void make_assertation ( const std::string &testname, const std::string &exp, const std::string &actual );
