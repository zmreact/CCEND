#include "input.h"

input :: input() {
    sseq = default_sseq.data();
    sdata = default_sdata.data();
    f_poly = default_sdata.data();
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
