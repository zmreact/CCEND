#include <stdio.h>
#include <iostream>
#include <bitset>

using namespace std;

class encoder {
public:
    encoder(const int * sdata, const int * f_poly);
    int ajdata();
    
private:
    const int * sdata;
    const int * f_poly;
    static const int N = 7;
    static const int K = 4;
    
};
