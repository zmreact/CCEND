// Input parser. Gets source sequence, source data (4-bit codes) and forming polynomial as an input.
#ifndef input_h
#define input_h

#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;


class input {
public:
    input();
    const int * s_sequence;
    const int * s_data;
    const int * s_data_size;
    
private:
    vector<int> default_s_sequence;
    vector<int> default_s_data;
    const int default_s_data_size;
};

#endif
