#include <iostream>
#include <math.h>
#include <unistd.h>
#include "../../include/shared.h"
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
    
    shmem_alloc_and_clean();
    shmem.attach();
    
    if (shmem.isAttached()) {
        cout << "Shared memory size: " << shmem.size() << " " << "Bytes";
        cout << endl << endl;
        
        input input;
        encoder encoder(&f_polynomial);
        
        while (true) {
            switch (TURN) {
                case E:
                    cout << "Source data codes: " << endl;
                    for (int i = 0; i < *input.s_data_size; i++) {
                        int * curr_dat = new int(input.s_data[input.s_sequience[i] - 1]);
                        cout << bitset<k>(*curr_dat) << " ";
                        delete curr_dat;
                    }
                    cout << endl << endl;
                    
                    cout << "Encoding to (7, 4) anti-jamming cyclic codes..." << endl;
                    cout << "Forming polynomial: " << endl;
                    cout << bitset<k>(f_polynomial) << endl;
                    cout << "Source anti-jamming codes:" << endl;
                    for (int i = 0; i < DATA_SIZE_INT; i++) {
                        int * curr_dat = new int(input.s_data[input.s_sequience[i] - 1]);
                        int * aj_data = new int(encoder.aj_data(curr_dat));

                        memcpy(DATA_PTR + i, aj_data, sizeof(*aj_data));

                        delete aj_data, curr_dat;
                    }
                    for (int i = 0; i < DATA_SIZE_INT; i++) cout << bitset<n>(*(DATA_PTR + i)) << " ";
                    cout << endl << endl;
                    
                    cout << "Sending...";
                    cout << endl << endl;
                    
                    WAIT_TURN;
                    
                    break;
                    
                default:
                    break;
                    
            }
            usleep(5000);
        }
    } else cout << "Shared memory is not attached" << endl << endl;
    
    shmem.detach();
    
    return 0;
}
