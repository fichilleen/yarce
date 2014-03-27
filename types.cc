#include "types.h"

// Use for lookups for human input and tests. This would be too slow to use
// for searching/etc. Plus, the computer doesn't really make moves based on
// notation, etc like a human does.
std::map <std::string,BitBoard*> file_rank_lookup;
std::vector <BitBoard*> bitboard_vector;

void init_lookups (){
    file_rank_lookup["A"] = (BitBoard*) &FILE_A;
    file_rank_lookup["B"] = (BitBoard*) &FILE_B;
    file_rank_lookup["C"] = (BitBoard*) &FILE_C;
    file_rank_lookup["D"] = (BitBoard*) &FILE_D;
    file_rank_lookup["E"] = (BitBoard*) &FILE_E;
    file_rank_lookup["F"] = (BitBoard*) &FILE_F;
    file_rank_lookup["G"] = (BitBoard*) &FILE_G;
    file_rank_lookup["H"] = (BitBoard*) &FILE_H;
    file_rank_lookup["1"] = (BitBoard*) &RANK_1;
    file_rank_lookup["2"] = (BitBoard*) &RANK_2;
    file_rank_lookup["3"] = (BitBoard*) &RANK_3;
    file_rank_lookup["4"] = (BitBoard*) &RANK_4;
    file_rank_lookup["5"] = (BitBoard*) &RANK_5;
    file_rank_lookup["6"] = (BitBoard*) &RANK_6;
    file_rank_lookup["7"] = (BitBoard*) &RANK_7;
    file_rank_lookup["8"] = (BitBoard*) &RANK_8;
}
