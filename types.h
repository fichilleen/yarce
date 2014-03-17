#ifndef YARCE_TYPES_H
#define YARCE_TYPES_H
 
typedef unsigned long long BitBoard;

typedef struct Boards {
    // White pieces 
    BitBoard WhitePawns;
    BitBoard WhiteKnights;
    BitBoard WhiteRooks;
    BitBoard WhiteBishops;
    BitBoard WhiteQueens;
    BitBoard WhiteKing;
    // Black pieces
    BitBoard BlackPawns;
    BitBoard BlackKnights;
    BitBoard BlackRooks;
    BitBoard BlackBishops;
    BitBoard BlackQueens;
    BitBoard BlackKing;
    // Meta positions
    BitBoard WhitePieces;
    BitBoard BlackPieces;
    BitBoard AllPieces;
} boards;

#endif /* YARCE_TYPES_H */
