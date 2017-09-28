// (7, 4) Hamming code encoder

#include "encoder.h"

encoder :: encoder
(const int * _f_polynomial) : f_polynomial(_f_polynomial) {};

int encoder :: aj_data(const int * _s_data) {
    const int * s_data = _s_data;
    
    int divider = *s_data << (n - k);
    int divident = *f_polynomial << (n - k);
    
    while (divider >= pow(2, n - k)) {
        divident = *f_polynomial << (n - k);
        for (int i = n; i > k; i--) {
            if (bitset<n>(divider).test(i - 1) == false) {
                divident >>= 1;
            } else break;
        }
        divider ^= divident;
    }
    divider += *s_data << (n - k);
    s_data++;
    
    return divider;
}
