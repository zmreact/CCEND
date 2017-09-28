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
    encoder(const int * _s_data, const int * _s_data_size, const int * _f_polynomial);
    const int * get_aj_data();
    
private:
    const int * const s_data;
    const int * const s_data_size;
    const int * const f_polynomial;
    vector<int> aj_data = {};
};
