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
        const int * s_data;
        const int * const s_data_size = input.s_data_size;
        const int * s_sequience;
        const int * const f_polynomial = input.f_polynomial;
        
        encoder encoder(f_polynomial);
        
        while (true) {
            switch (TURN) {
                case E:
                    s_data = input.s_data;
                    s_sequience = input.s_sequience;
                    for (int i = 0; i < *s_data_size; i++) {
                        const int * s_data_i = new const int(s_data[*s_sequience - 1]);
                        int * aj_data = new int(encoder.aj_data(s_data_i));
                        int aj_data_size = sizeof(*aj_data);
                        
                        memcpy(DATA_PTR + i, aj_data, aj_data_size);
                        s_sequience++;
                        
                        delete s_data_i, delete aj_data;
                    }
                    
                    cout << "Source data codes: " << endl;
                    s_data = input.s_data;
                    s_sequience = input.s_sequience;
                    for (int i = 0; i < *s_data_size; i++) cout << bitset<k>(s_data[*s_sequience++ - 1]) << " ";
                    cout << endl << endl;
                    
                    cout << "Encoding to (7, 4) anti-jamming cyclic codes..." << endl;
                    cout << "Forming polynomial: " << endl;
                    cout << bitset<k>(*f_polynomial) << endl;
                    cout << "Source anti-jamming codes:" << endl;
                    for (int i = 0; i < *s_data_size; i++) cout << bitset<n>(*(DATA_PTR + i)) << " ";
                    cout << endl << endl;
                    
                    cout << "Sending...";
                    cout << endl << endl;
                    
                    WAIT_TURN;
                    
                    break;
                    
                case N:
                    break;
                    
                case D:
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
