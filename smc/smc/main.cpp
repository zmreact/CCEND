// Shared memory controller
#include "main.h"

int main(int argc, const char * argv[]) {
    shmem.create(D_OFFSET + D_SIZE);
    shmem.attach();
    EUP_0;
    NUP_0;
    DUP_0;

    while (shmem.isAttached()) {
        if (shmem.isAttached()) {
            if (kill(EPID, 0) == 0) {
                cout << "Encoder is alive" << endl;
            } else if (errno == ESRCH) {
                cout << "Encoder is down" << endl;
                EUP_0;
            }
            if (kill(NPID, 0) == 0) {
                cout << "Noise generator is alive" << endl;
            } else if (errno == ESRCH) {
                cout << "Noise generator is down" << endl;
                NUP_0;
            }
            if (kill(DPID, 0) == 0) {
                cout << "Decoder is alive" << endl;
            } else if (errno == ESRCH) {
                cout << "Decoder is down" << endl;
                DUP_0;
            }
        } else cout << "Shared memory is not attached" << endl << endl;
        cout << endl;
        
        sleep(3);
        
        if (kill(EPID, 0) != 0 && kill(NPID, 0) != 0 && kill(DPID, 0) != 0) {
            shmem.detach();
        }
    }
    return 0;
}
