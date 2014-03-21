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

#include "shift_test.h"

#define SHIFT_EAST << 1

void king_shift ( BitBoard &king, direction shift_dir ){
    if ( shift_dir == EAST ){
        if ( ! (file_h & king)){
            king = king SHIFT_EAST;
        }
    }
}


