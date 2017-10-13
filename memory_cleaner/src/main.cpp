// Shared memory cleaner
#include <iostream>
#include "../../include/shared.h"


int main(int argc, const char * argv[]) {
    QSystemSemaphore sema("/sema", 1);
    
    sema.acquire();
    if (owed_shmem.attach()) {
        std::cout << "Cleaning if unattached shared memory is present..." << std::endl;
        owed_shmem.detach();
        std::cout << "OK" << std::endl << std::endl;
    }
    else {
        std::cout << "Nothing to clean" << std::endl << std::endl;
    }
    sema.release();
    
    return 0;
}
