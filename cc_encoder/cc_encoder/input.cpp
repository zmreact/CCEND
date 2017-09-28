// Input parser. Gets source sequence, source data (4-bit codes) and forming polynomial as an input.

#include "input.h"

const vector<const int> input ::
default_s_sequience({2, 4, 6, 8, 10, 12, 14, 16, 1, 3, 5, 7, 9, 11, 13, 15});
const vector<const int> input ::
default_s_data({0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110, 0b0111, 0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101, 0b1110, 0b1111});
const int input ::
default_s_data_size((const int) default_s_data.size());

input :: input() : f_polynomial(&default_f_polynomial), s_sequience(default_s_sequience.data()), s_data(default_s_data.data()), s_data_size(&default_s_data_size) {};

input :: input(const char * inputpath[]) {
    fstream input;
    input.open(* inputpath, fstream::in);
    if (input.is_open()) {
        // parser
    }
    else inputerr = true;
    input.close();
}
