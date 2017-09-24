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
        SET_DPID;
        DUP_1;
        cout << "Shared memory size: " << shmem.size() << " " << "Bytes";
        cout << endl << endl;
        
        while (DUP) {
            switch (STATE) {
                case E:
                    cout << "E_STATE" << endl;
                    
                    sleep(1);
                    
                    break;
                case N:
                    cout << "N_STATE" << endl;
                    
                    if (!NUP) SWITCH_TO_D_STATE;
                    sleep(1);
                    
                    break;
                case D:
                    cout << "D_STATE" << endl;
                    
                    cout << "Received anti-jamming codes: " << endl;
                    // codes to out
                    cout << endl << endl;
                    
                    cout << "Decoding (7, 3) anti-jamming codes..." << endl;
                    cout << "Forming polynomial: " << std::bitset<4>(polynom) << endl;
                    cout << "Received data codes:" << endl;
                    for (int i = 0; i < 16; i++) {
                        cout << bitset<4>(* ((int *) shmem.data() + D_OFFSET + i * sizeof(i))) << " ";
                    }
                    cout << endl << endl;
                    SWITCH_TO_E_STATE;
                    
                    break;
            }
        }
        shmem.detach();
    }
    else cout << "Shared memory is not attached" << endl << endl;
    
    return 0;
}
