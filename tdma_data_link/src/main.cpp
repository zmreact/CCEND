// TDMA realization

#include <iostream>
#include "../../include/shared.h"
#include "../../include/library.h"

int main(int argc, const char * argv[]) {
    shmem_alloc_and_clean();
    shmem.attach();
    
    while (true) {
        GIVE_E_TURN;
        std::cout << "E_TURN" << std::endl;
        cpsleep(50);
        GIVE_N_TURN;
        std::cout << "N_TURN" << std::endl;
        cpsleep(50);
        GIVE_D_TURN;
        std::cout << "D_TURN" << std::endl;
        cpsleep(50);
    }
    
    shmem.detach();
    
    return 0;
}
