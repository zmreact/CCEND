#include <iostream>
#include <math.h>
#include "../../include/shared.h"
#include "../../include/library.h"
#include "decoder.h"
using namespace std;

#define UNIVERSITY "MTUCI"
#define STGROUP "BSU1401"
#define DEVELOPERS "Denis Petuhov, Kaledina Anastasija, Korotygin Aleksandr, Ezhova Elena, Krasnov Kirill"

void main(int argc, const char * argv[]) {
    cout
    << "University: " <<        UNIVERSITY <<       endl
    << "Student group: " <<     STGROUP <<          endl
    << "Developers: " <<        DEVELOPERS <<       endl
    << endl;
    
    shmem_alloc_and_clean();
    shmem.attach();
    
    if (shmem.isAttached()) {
        cout << "Shared memory size: " << shmem.size() << " " << "Bytes";
        cout << endl << endl;
        
        decoder Decoder;

        while (true) {
            switch (TURN) {
                case D:
                    cout << "Received anti-jamming codes: " << endl;
                    
                    for (int i = 0; i < DATA_SIZE_INT; i++) cout << bitset<n>(*(DATA_PTR + i)) << " ";
                    cout << endl << endl;
                    
                    cout << "Decoding (7, 3) anti-jamming codes..." << endl;
                    
                    cout << "Received data codes:" << endl;
                    
                    for (int i = 0; i < DATA_SIZE_INT; i++) cout << bitset<k>(Decoder.d_data(DATA_PTR + i)) << " ";
                    cout << endl << endl;
                    
                    WAIT_TURN;
                    
                    break;
                    
                default:
                    break;
                    
            }
            cpsleep(500);
        }
        shmem.detach();
    }
    else cout << "Shared memory is not attached" << endl << endl;
}
