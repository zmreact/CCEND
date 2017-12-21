// TDMA realization

#include <iostream>
#include "../../include/shared.h"
#include "../../include/library.h"

void main(int argc, const char * argv[]) {
    shmem_alloc_and_clean();
    shmem.attach();

    if (shmem.isAttached()) {
        while (true) {
            PASS_TURN_E;
            std::cout << "E_TURN" << std::endl;
            cpsleep(17);
            PASS_TURN_N;
            std::cout << "N_TURN" << std::endl;
            cpsleep(17);
            PASS_TURN_D;
            std::cout << "D_TURN" << std::endl;
            cpsleep(17);
        }
    }
}
