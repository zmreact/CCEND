// Shared memory realization
#ifndef shared_h
#define shared_h


#include <iostream>
#include <QtCore/qsharedmemory.h>
#include <QtCore/qsystemsemaphore.h>

static const int n =            7;
static const int k =            4;
static const int f_polynomial = 0b1011;

static QSystemSemaphore         sema("/sema", 1);
static QSharedMemory            owed_shmem("/shmem");
static QSharedMemory            shmem("/shmem");

void shmem_alloc_and_clean();

enum turns {E, N, D, W};
static const turns E_TURN =     E;
static const turns N_TURN =     N;
static const turns D_TURN =     D;
static const turns WAIT_TURN =  W;

#define TURN_OFFSET             0
#define DATA_OFFSET             4
#define DATA_SIZE               64
#define DATA_SIZE_INT           16

#define TURN_PTR                ((turns * const) shmem.data() + TURN_OFFSET)
#define DATA_PTR                ((int * const) shmem.data() + DATA_OFFSET)

#define TURN                    *TURN_PTR

#define GIVE_E_TURN             memcpy(TURN_PTR, &E_TURN, sizeof(E_TURN))
#define GIVE_N_TURN             memcpy(TURN_PTR, &N_TURN, sizeof(N_TURN))
#define GIVE_D_TURN             memcpy(TURN_PTR, &D_TURN, sizeof(D_TURN))
#define WAIT_TURN               memcpy(TURN_PTR, &WAIT_TURN, sizeof(WAIT_TURN))


#endif
