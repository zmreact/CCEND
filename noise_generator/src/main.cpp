// Noise generator

#include <iostream>
#include <math.h>
#include "../../include/library.h"
#include "../../include/shared.h"
using namespace std;

void main(int argc, const char * argv[]) {
    shmem_alloc_and_clean();
    shmem.attach();
    
    if (shmem.isAttached()) {
        while (true) {
            switch (TURN) {
                case N:
                    cout << "Generating noise..." << endl << endl;
                    for (int i = 0; i < DATA_SIZE_INT; i++) {
                        const int noise = 0b0000001 << (rand() % 7 + 0);
                        int noise_plus_data = noise ^ *(DATA_PTR + i);
                        memcpy(DATA_PTR + i, &noise_plus_data, sizeof(noise_plus_data));
                    }

                    WAIT_TURN;

                    break;

                default:
                    break;
                    
            }
            cpsleep(500);
        }
    }
}
