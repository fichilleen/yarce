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

#include <map>
#include <string>
#include <vector>

#ifndef YARCE_TYPES_H
#define YARCE_TYPES_H
 
typedef unsigned long long BitBoard;

typedef struct Boards {
    // white_ pieces 
    BitBoard white_pawns;
    BitBoard white_knights;
    BitBoard white_rooks;
    BitBoard white_bishops;
    BitBoard white_queens;
    BitBoard white_king;
    // black_ pieces
    BitBoard black_pawns;
    BitBoard black_knights;
    BitBoard black_rooks;
    BitBoard black_bishops;
    BitBoard black_queens;
    BitBoard black_king;
    // Meta positions
    BitBoard empty;
    BitBoard white_pieces;
    BitBoard black_pieces;
    BitBoard all_pieces;
} boards;

// NOTE: The following code defining ranks and files is more or less copied
// straight from stockfish. A very strong FOSS chess engine:
// https://github.com/mcostalba/Stockfish

const BitBoard FILE_A = 0x0101010101010101ULL;
const BitBoard FILE_B = FILE_A << 1;
const BitBoard FILE_C = FILE_A << 2;
const BitBoard FILE_D = FILE_A << 3;
const BitBoard FILE_E = FILE_A << 4;
const BitBoard FILE_F = FILE_A << 5;
const BitBoard FILE_G = FILE_A << 6;
const BitBoard FILE_H = FILE_A << 7;

const BitBoard RANK_1 = 0xFF;
const BitBoard RANK_2 = RANK_1 << (8 * 1);
const BitBoard RANK_3 = RANK_1 << (8 * 2);
const BitBoard RANK_4 = RANK_1 << (8 * 3);
const BitBoard RANK_5 = RANK_1 << (8 * 4);
const BitBoard RANK_6 = RANK_1 << (8 * 5);
const BitBoard RANK_7 = RANK_1 << (8 * 6);
const BitBoard RANK_8 = RANK_1 << (8 * 7);

extern std::map <char,BitBoard*> file_rank_lookup;
extern std::vector <BitBoard*> bitboard_vector;
void init_lookups();

#endif /* YARCE_TYPES_H */
