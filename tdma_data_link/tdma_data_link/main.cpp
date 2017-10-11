// TDMA realization

#include <iostream>
#include "../../include/shared.h"
using namespace std;

int main(int argc, const char * argv[]) {
    shmem_alloc_and_clean();
    shmem.attach();
    
    while (true) {
        GIVE_E_TURN;
        cout << "E_TURN" << endl;
        usleep(50000);
        GIVE_N_TURN;
        cout << "N_TURN" << endl;
        usleep(50000);
        GIVE_D_TURN;
        cout << "D_TURN" << endl;
        usleep(50000);
    }
    
    shmem.detach();
    
    return 0;
}
