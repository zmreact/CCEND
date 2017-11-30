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
    decoder();
    int d_data(const int * _aj_data);
    int get_syndrome(const int * _aj_data);
    
private:
    vector<int> error_vectors;
    vector<int> error_vectors_syndromes;
    
};

#endif
