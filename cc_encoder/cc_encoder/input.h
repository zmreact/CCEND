// Input parser. Gets source sequence, source data (4-bit codes) and forming polynomial as an input.

#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;


class input {
public:
    input();
    input(const char * inputpath[]);
    const int * s_sequience;
    const int * s_data;
    const int * s_data_size;
    const int * f_polynomial;
    bool inputerr = false;
    
private:
    int parse_fpoly (const char * argv[]);
    static const vector<const int> default_s_sequience;
    static const vector<const int> default_s_data;
    static const int default_s_data_size;
    const int default_f_polynomial = 0b1011;
};
