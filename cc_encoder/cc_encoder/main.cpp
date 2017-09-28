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
        int * const shmem_data_pointer = (int *) shmem.data() + D_OFFSET;
        const int shmem_size = shmem.size();
        
        cout << "Shared memory size: " << shmem_size << " " << "Bytes";
        cout << endl << endl;
        
        SET_ENCODER_PID;
        EUP_1;
        SWITCH_TO_E_STATE;
        
        while (EUP) {
            switch (STATE) {
                case E:
                {
                    input input;
                    const int * s_data = input.s_data;
                    const int * s_data_size = input.s_data_size;
                    const int * s_sequience = input.s_sequience;
                    const int * f_polynomial = input.f_polynomial;
                    
                    encoder encoder(s_data, s_data_size, f_polynomial);
                    const int * aj_data = encoder.get_aj_data();
                    const int aj_data_size = sizeof(*aj_data) * n;
                    memcpy(shmem_data_pointer, aj_data, aj_data_size);
                    
                    
                    cout << "E_STATE" << endl << endl;
                    
                    cout << "Source data codes: " << endl;
                    for (int i = 0; i < *s_data_size; i++) {
                        cout << bitset<k>(s_data[*s_sequience - 1]) << " ";
                        s_sequience++;
                    }
                    cout << endl << endl;
                    
                    cout << "Encoding to (7, 4) anti-jamming cyclic codes..." << endl;
                    cout << "Forming polynomial: " << endl;
                    cout << bitset<k>(*f_polynomial) << endl;
                    cout << "Source anti-jamming codes:" << endl;
                    
                    for (int i = 0; i < *s_data_size; i++) {
                        cout << bitset<n>(* (shmem_data_pointer + i)) << " ";
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
