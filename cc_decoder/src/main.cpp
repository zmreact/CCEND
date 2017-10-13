#include <iostream>
#include <math.h>
#include <unistd.h>
#include "../../include/shared.h"
#include "decoder.h"
using namespace std;

#define UNIVERSITY "MTUCI"
#define STGROUP "BSU1401"
#define DEVELOPERS "Denis Petuhov, Kaledina Anastasija, Korotygin Aleksandr, Ezhova Elena, Krasnov Kirill"

int main(int argc, const char * argv[]) {
    cout
    << "University: " <<        UNIVERSITY <<       endl
    << "Student group: " <<     STGROUP <<          endl
    << "Developers: " <<        DEVELOPERS <<       endl
    << endl;
    
    shmem_alloc_and_clean();
    shmem.attach();
    
    decoder decoder(&f_polynomial);
    
    if (shmem.isAttached()) {
        cout << "Shared memory size: " << shmem.size() << " " << "Bytes";
        cout << endl << endl;
        
        while (true) {
            switch (TURN) {
                case E:
                    break;
                    
                case N:
                    break;
                    
                case D:
                    cout << "Received anti-jamming codes: " << endl;
                    
                    for (int i = 0; i < DATA_SIZE_INT; i++) cout << bitset<n>(*(DATA_PTR + i)) << " ";
                    cout << endl << endl;
                    
                    
                    cout << "Decoding (7, 3) anti-jamming codes..." << endl;
                    
                    cout << "Received data codes:" << endl;
                    
                    for (int i = 0; i < DATA_SIZE_INT; i++) cout << bitset<k>(decoder.d_data(DATA_PTR + i)) << " ";
                    cout << endl << endl;
                    
                    
                    WAIT_TURN;
                    
                    
                    break;
                    
                default:
                    break;
                    
            }
            usleep(5000);
        }
        shmem.detach();
    }
    else cout << "Shared memory is not attached" << endl << endl;
    
    return 0;
}
