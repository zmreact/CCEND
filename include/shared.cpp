// Shared memory realization
#include "shared.h"
#include <iostream>

void shmem_alloc_and_clean () {
    sema.acquire();
    if (owed_shmem.attach()) {
        owed_shmem.detach();
    }
    if (!shmem.attach()) {
        shmem.create(DATA_OFFSET + DATA_SIZE);
        std::cout << "Shared memory created\n";
    }
    sema.release();
}
