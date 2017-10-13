// (7, 4) Hamming code encoder
#ifndef encoder_h
#define encoder_h

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <math.h>
#include "../../include/shared.h"

using namespace std;

class encoder {
public:
    encoder(const int * const _f_polynomial);
    int aj_data(const int * _s_data);
    int get_syndrome(const int * _s_data);
    
private:
    const int * const f_polynomial;
};

#endif
