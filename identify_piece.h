#include "types.h"
#include <map>
#include <string>

class IdentifyPiece{
    std::map <std::string,BitBoard> file_map;
public:
    IdentifyPiece ();
    void print_piece ( std::string which_file, std::string which_rank );
};
