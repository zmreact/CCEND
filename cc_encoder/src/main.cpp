#include <iostream>
#include "../../include/shared.h"
#include "../../include/library.h"
#include "input.h"
#include "encoder.h"

#define UNIVERSITY "MTUCI"
#define STGROUP "BSU1401"
#define DEVELOPERS "Denis Petuhov, Kaledina Anastasija, Korotygin Aleksandr, Ezhova Elena, Krasnov Kirill"

int main(int argc, const char * argv[]) {
    std::cout << "University: " << UNIVERSITY << std::endl << "Student group: " << STGROUP << std::endl << "Developers: " << DEVELOPERS;
    std::cout << std::endl << std::endl;
    
    shmem_alloc_and_clean();
    shmem.attach();
    
    
    if (shmem.isAttached()) {
        std::cout << "Shared memory size: " << shmem.size() << " " << "Bytes";
        std::cout << std::endl << std::endl;
        
        input input;
        encoder Encoder;
        
        while (true) {
            switch (TURN) {
                case E:
                    std::cout << "Source data codes: " << std::endl;
                    
                    for (int i = 0; i < *input.s_data_size; i++) {
                        int * curr_dat = new int(input.s_data[input.s_sequence[i] - 1]);
                        std::cout << bitset<k>(*curr_dat) << " ";
                        delete curr_dat;
                    }
                    
                    std::cout << std::endl << std::endl;
                    
                    
                    std::cout << "Encoding to (7, 4) anti-jamming cyclic codes..." << std::endl;
                    
                    std::cout << "Forming polynomial: " << std::endl;
                    
                    std::cout << bitset<k>(f_polynomial) << std::endl;
                    
                    std::cout << "Source anti-jamming codes:" << std::endl;
                    
                    for (int i = 0; i < DATA_SIZE_INT; i++) {
                        int * curr_dat = new int(input.s_data[input.s_sequence[i] - 1]);
                        int * aj_data = new int(Encoder.aj_data(curr_dat));
                        memcpy(DATA_PTR + i, aj_data, sizeof(*aj_data));
                        delete aj_data;
                        delete curr_dat;
                    }
                    
                    for (int i = 0; i < DATA_SIZE_INT; i++) std::cout << bitset<n>(*(DATA_PTR + i)) << " ";
                    std::cout << std::endl << std::endl;
                    
                    
                    std::cout << "Sending...";
                    std::cout << std::endl << std::endl;
                    
                    
                    WAIT_TURN;
                    
                    
                    break;
                    
                default:
                    break;
                    
            }
            cpsleep(10);
        }
    } else std::cout << "Shared memory is not attached" << std::endl << std::endl;
    
    shmem.detach();
    
    return 0;
}
