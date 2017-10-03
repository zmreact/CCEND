// (7, 4) Hamming code decoder
#ifndef decoder_h
#define decoder_h

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <math.h>
#include <vector>
#include "../../include/shared.h"
#include <algorithm>

using namespace std;

class decoder {
public:
    decoder(const int * const _f_polynomial);
    int d_data(const int * _aj_data);
    int get_syndrome(const int * _aj_data);
    
private:
    const int * const f_polynomial;
    const vector<const int> error_vectors;
    const vector<const int> error_vectors_syndromes;
    
};

#endif
