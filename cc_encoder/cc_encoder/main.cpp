#include <iostream>
#include <math.h>
#include <unistd.h>
#include "shared.h"
#include "input.h"
#include "encoder.h"
using namespace std;


#define UNIVERSITY "MTUCI"
#define STGROUP "BSU1401"
#define DEVELOPERS "Denis Petuhov, Kaledina Anastasija, Korotygin Aleksandr, Ezhova Elena, Krasnov Kirill"

int main(int argc, const char * argv[]) {
    cout << "University: " << UNIVERSITY << endl
    << "Student group: " << STGROUP << endl
    << "Developers: " << DEVELOPERS;
    cout << endl << endl;
    
    shmem.attach();
    if (shmem.isAttached()) {
        cout << "Shared memory size: " << shmem.size() << " " << "Bytes";
        cout << endl << endl;
        
        SET_EPID;
        EUP_1;
        SWITCH_TO_E_STATE;
        STATE = E;
        

        while (EUP) {
            switch (STATE) {
                case E:
                {
                    cout << "E_STATE" << endl << endl;
                    
                    cout << "Source data codes: " << endl;
                    input input;
                    for (int i = 0; i < * input.sdatasize; i++) {
                        memcpy((int *) shmem.data() + D_OFFSET + i, &input.sdata[*input.sseq - 1], sizeof(*input.sdata));
                        input.sseq++;
                    }
                    
                    for (int i = 0; i < * input.sdatasize; i++) {
                        cout << bitset<4>(* ((int *) shmem.data() + D_OFFSET + i)) << " ";
                    }
                    cout << endl << endl;
                    
                    cout << "Encoding to (7, 4) anti-jamming cyclic codes..." << endl;
                    cout << "Forming polynomial: " << endl;
                    cout << bitset<4>(*input.f_poly) << endl;
                    cout << "Source anti-jamming codes:" << endl;
                    encoder encoder((const int *) shmem.data() + D_OFFSET, input.f_poly);
                    for (int i = 0; i < * input.sdatasize; i++) {
                        encoder.ajdata();
                    }
                    cout << endl << endl;
                    
                    cout << "Sending...";
                    cout << endl << endl;

                    if (NUP) SWITCH_TO_N_STATE;
                    else SWITCH_TO_D_STATE;
                    break;
                }
                case N:
                    cout << "N_STATE" << endl << endl;
                    
                    if (!NUP) SWITCH_TO_D_STATE;
                    sleep(1);
                    
                    break;
                case D:
                    cout << "D_STATE" << endl << endl;
                    
                    sleep(1);
                    
                    break;
            }
        }
    } else cout << "Shared memory is not attached" << endl << endl;
    
    shmem.detach();
    
    return 0;
}
