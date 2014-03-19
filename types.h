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

#endif /* YARCE_TYPES_H */
