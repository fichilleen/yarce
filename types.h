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
    BitBoard white_pieces;
    BitBoard black_pieces;
    BitBoard all_pieces;
} boards;

const BitBoard file_a = 0x0101010101010101ULL;
const BitBoard file_b = file_a << 1;
const BitBoard file_c = file_a << 2;
const BitBoard file_d = file_a << 3;
const BitBoard file_e = file_a << 4;
const BitBoard file_f = file_a << 5;
const BitBoard file_g = file_a << 6;
const BitBoard file_h = file_a << 7;

// Directions
typedef unsigned short direction;
# define NORTHWEST 1
# define NORTH 2
# define NORTHEAST 3
# define EAST 4

#endif /* YARCE_TYPES_H */
