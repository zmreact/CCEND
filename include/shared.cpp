// Shared memory realization

#include "shared.h"
#include <iostream>

void shmem_alloc_and_clean () {
    sema.acquire();
    if (owed_shmem.attach()) {
        std::cout << "Cleaning shared memory\n";
        owed_shmem.detach();
        std::cout << "Shared memory cleaned\n";
    }
    if (!shmem.attach()) {
        shmem.create(D_OFFSET + D_SIZE);
        std::cout << "Shared memory created\n";
    }
    sema.release();
}
