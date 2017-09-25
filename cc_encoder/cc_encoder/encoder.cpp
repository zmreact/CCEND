#include "encoder.h"

encoder :: encoder (const int * _sdata, const int * _f_poly) {
    sdata = _sdata;
    f_poly = _f_poly;
}

int encoder :: ajdata() {
    int divider = * sdata << (N - K);
    int divident = * f_poly << (N - K);
    
    cout << "Divider: " << bitset<N>(divider) << endl;
    cout << "Divident: " << bitset<N>(divident) << endl;
    
    while (divider > 0b111) {
        divident = * f_poly << (N - K);
        for (int i = N; i > K; i--) {
            if (bitset<N>(divider).test(i - 1) == false) {
                divident >>= 1;
            } else break;
        }
        divider ^= divident;
    }
    
    cout << "Syndrom: " << bitset<(N - K)>(divider) << endl << endl;
    
    divider += * sdata << (N - K);
    sdata++;
    
    return divider;
}
