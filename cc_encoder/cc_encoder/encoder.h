// (7, 4) Hamming code encoder

#include <stdio.h>
#include <iostream>
#include <bitset>
#include <math.h>
#include <vector>

using namespace std;

static const int n = 7;
static const int k = 4;

class encoder {
public:
    encoder(const int * const _f_polynomial);
    int aj_data(const int * _s_data);
    
private:
    const int * const f_polynomial;
};
