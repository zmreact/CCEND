// Noise generator
#include "main.h"

int main(int argc, const char * argv[]) {
    shmem.attach();
    
    if (shmem.isAttached()) {
        SET_NPID;
        NUP_1;
        
        while (NUP) {
            switch (STATE) {
                case E:
                    cout << "E_STATE" << endl;
                    sleep(1);
                    break;
                case N:
                    cout << "N_STATE" << endl;
                    
                    cout << "Generating noise..." << endl;
                    for (int i = 0; i < 16; i++) {
                        memcpy((int *) shmem.data() + D_OFFSET + i * sizeof(i), new int(i + 6), sizeof(int));
                    }
                    SWITCH_TO_D_STATE;
                    sleep(1);
                    break;
                case D:
                    cout << "D_STATE" << endl;
                    sleep(1);
                    break;
            }
        }
    }
    
    shmem.detach();
    
    return 0;
}
