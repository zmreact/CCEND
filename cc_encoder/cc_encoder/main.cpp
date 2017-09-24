#include "main.h"

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
        
        

        while (EUP) {
            switch (STATE) {
                case E:
                    cout << "E_STATE" << endl << endl;
                    
                    cout << "Source data codes: " << endl;
                    for (const int * i = sseq; i < sseq + sizeof(sseq) / sizeof(* sseq) - 1; i++) {
                        input input;
                        memcpy(&d_pointer, &sdata[* i - 1], sizeof(* sdata));
                    }
                    for (int i = 0; i < 16; i++) {
                        cout << bitset<4>(* ((int *) shmem.data() + D_OFFSET + i * sizeof(i))) << " ";
                    }
                    cout << endl << endl;
                    
                    cout << "Encoding (7, 3) anti-jamming codes..." << endl;
                    cout << "Forming polynomial: " << std::bitset<4>(f_poly) << endl;
                    cout << "Source anti-jamming codes:" << endl;
                    // codes to out
                    cout << endl << endl;
                    
                    cout << "Sending...";
                    cout << endl << endl;

                    if (NUP) SWITCH_TO_N_STATE;
                    else SWITCH_TO_D_STATE;
                    
                    break;
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
