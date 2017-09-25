#include "input.h"

input :: input() {
    sseq = &default_sseq[0];
    sdata = &default_sdata[0];
    sdatasize = &default_sdatasize;
    f_poly = &default_f_poly;

}

input :: input(const char * inputpath[]) {
    fstream input;
    input.open(* inputpath, fstream::in);
    if (input.is_open()) {
        // parser
    }
    else inputerr = true;
    input.close();
}
