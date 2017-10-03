// (7, 4) Hamming code decoder
#include "decoder.h"

decoder :: decoder (const int * _f_polynomial) :
f_polynomial              (_f_polynomial),
error_vectors             ({0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b1000000}),
error_vectors_syndromes   ({0b001, 0b010, 0b100, 0b011, 0b110, 0b111, 0b101})
{}
;

int decoder :: get_syndrome(const int * _s_data) {
    const int * s_data = _s_data;
    int divider = *s_data;
    int divident = 0;
    while (divider >= pow(2, n - k)) {
        divident = *f_polynomial << (n - k);
        for (int i = n; i > k; i--) {
            if (bitset<n>(divider).test(i - 1) == false) {
                divident >>= 1;
            } else break;
        }
        divider ^= divident;
    }
    return divider;
}

int decoder :: d_data(const int * _aj_data) {
    const int * aj_data = _aj_data;
    
    int syndrome = get_syndrome(aj_data);
    int error_vector = 0;
    int d_data = *aj_data >> (n - k);
    
    if (syndrome != 0) {
        auto it = find(error_vectors_syndromes.begin(), error_vectors_syndromes.end(), syndrome);
        error_vector = error_vectors.at(it - error_vectors_syndromes.begin());
        d_data = (*aj_data ^ error_vector) >> (n - k);
    }
    
    
    return d_data;
}
