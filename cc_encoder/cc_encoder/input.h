#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;


class input {
public:
    input();
    input(const char * inputpath[]);
    const int * sseq;
    const int * sdata;
    const int * f_poly;
    bool inputerr = false;
    
private:
    int parse_fpoly (const char * argv[]);
    vector<const int> default_sseq = {1, 3, 5, 7, 9, 11, 13, 15, 2, 4, 6, 8, 10, 12, 14, 16};
    vector<const int> default_sdata = {0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110,
                                       0b0111, 0b1000, 0b1001, 0b1010, 0b1011, 0b1100, 0b1101,
                                       0b1110, 0b1111};
    const int default_f_poly = 0b1011;

};
