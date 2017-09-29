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
    sema.acquire();
    shmem.attach();
    
    if (shmem.isAttached()) {
        int * const shmem_data_pointer = (int * const) shmem.data() + D_OFFSET;
        const int shmem_size = shmem.size();
        
        cout << "Shared memory size: " << shmem_size << " " << "Bytes";
        cout << endl << endl;
        
        SET_ENCODER_PID;
        SET_E_UP;
        GIVE_E_TURN;
        
        while (E_STATE) {
            switch (TURN) {
                case E:
                {
                    input input;
                    const int * s_data;
                    const int * const s_data_size = input.s_data_size;
                    const int * s_sequience;
                    const int * const f_polynomial = input.f_polynomial;
                    
                    encoder encoder(f_polynomial);
                    
                    //writing (7, 4) codes to shared memory
                    s_data = input.s_data;
                    s_sequience = input.s_sequience;
                    for (int i = 0; i < *s_data_size; i++) {
                        const int * s_data_i = new const int(s_data[*s_sequience - 1]);
                        int * aj_data = new int(encoder.aj_data(s_data_i));
                        int aj_data_size = sizeof(*aj_data);
                        
                        memcpy(shmem_data_pointer + i, aj_data, aj_data_size);
                        s_sequience++;
                        
                        delete s_data_i, delete aj_data;
                    }
                    
                    
                    cout << "E_TURN" << endl << endl;
                    
                    cout << "Source data codes: " << endl;
                    s_data = input.s_data;
                    s_sequience = input.s_sequience;
                    for (int i = 0; i < *s_data_size; i++) cout << bitset<k>(s_data[*s_sequience++ - 1]) << " ";
                    cout << endl << endl;
                    
                    cout << "Encoding to (7, 4) anti-jamming cyclic codes..." << endl;
                    cout << "Forming polynomial: " << endl;
                    cout << bitset<k>(*f_polynomial) << endl;
                    cout << "Source anti-jamming codes:" << endl;
                    for (int i = 0; i < *s_data_size; i++) cout << bitset<n>(*(shmem_data_pointer + i)) << " ";
                    cout << endl << endl;
                    
                    cout << "Sending...";
                    cout << endl << endl;

                    if (N_STATE) {
                        sema.release();
                        GIVE_N_TURN;
                    }
                    else {
                        sema.release();
                        GIVE_D_TURN;
                    }
                    break;
                }
                case N:
                    cout << "N_TURN" << endl << endl;
                    
                    if (!N_STATE) GIVE_D_TURN;
                    sleep(1);
                    
                    break;
                case D:
                    cout << "D_TURN" << endl << endl;
                    
                    sleep(1);
                    
                    break;
            }
        }
    } else cout << "Shared memory is not attached" << endl << endl;
    
    shmem.detach();
    
    return 0;
}
