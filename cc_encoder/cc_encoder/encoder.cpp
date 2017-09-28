// (7, 4) Hamming code encoder

#include "encoder.h"

encoder :: encoder
(const int * _s_data, const int * _s_data_size, const int * _f_polynomial) : s_data(_s_data), s_data_size(_s_data_size), f_polynomial(_f_polynomial) {};

const int * encoder :: get_aj_data() {
    const int * s_data_ = s_data;
    
    while (s_data_ < s_data + *s_data_size) {
        int divider = *s_data_ << (n - k);
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
        divider += *s_data_ << (n - k);
        aj_data.push_back(divider);
        s_data_++;
    }
    return aj_data.data();
}
