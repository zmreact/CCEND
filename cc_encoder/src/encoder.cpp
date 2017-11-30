// (7, 4) Hamming code encoder
#include "encoder.h"

encoder :: encoder()
{

}

int encoder :: aj_data(const int * _s_data) {
    const int * s_data = _s_data;
    
    int syndrome = get_syndrome(_s_data);
    int aj_data = *s_data << (n - k);
    
    aj_data += syndrome;
    
    return aj_data;
}

int encoder :: get_syndrome(const int * _s_data) {
    const int * s_data = _s_data;
    int divider = *s_data << (n - k);
    int divident = 0;
    while (divider >= pow(2, n - k)) {
        divident = f_polynomial << (n - k);
        for (int i = n; i > k; i--) {
            if (bitset<n>(divider).test(i - 1) == false) {
                divident >>= 1;
            } else break;
        }
        divider ^= divident;
    }
    return divider;
}

