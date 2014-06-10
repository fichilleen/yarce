#ifndef YARCE_BITTLESHIP_UTILS_H
#define YARCE_BITTLESHIP_UTILS_H
#include "../types.h"

void draw_board ( const BitBoard &hit, const BitBoard &missed, const BitBoard &placed, const BitBoard &sank );
void intersect_file_rank ( BitBoard &new_board, const char &file, const char &rank );
void board_to_char ( const BitBoard &board, char &file, char &rank );

#endif
