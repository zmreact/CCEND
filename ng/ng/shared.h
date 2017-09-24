#include <QtCore/qsharedmemory.h>

QSharedMemory shmem("/shmem", nullptr);
#define STATE_OFFSET 0
#define EUP_OFFSET 4
#define EPID_OFFSET 5
#define NUP_OFFSET 9
#define NPID_OFFSET 10
#define DUP_OFFSET 14
#define DPID_OFFSET 15
#define D_OFFSET 19
#define D_SIZE 64

enum states {E, N, D};
#define E_STATE * (new states(E))
#define N_STATE * (new states(N))
#define D_STATE * (new states(D))

#define SWITCH_TO_E_STATE memcpy((states *) shmem.data() + STATE_OFFSET, &E_STATE, sizeof(E_STATE))
#define SWITCH_TO_N_STATE memcpy((states *) shmem.data() + STATE_OFFSET, &N_STATE, sizeof(N_STATE))
#define SWITCH_TO_D_STATE memcpy((states *) shmem.data() + STATE_OFFSET, &D_STATE, sizeof(D_STATE))

#define STATE * ((states *) shmem.data() + STATE_OFFSET)
#define EUP * ((bool *) shmem.data() + EUP_OFFSET)
#define NUP * ((bool *) shmem.data() + NUP_OFFSET)
#define DUP * ((bool *) shmem.data() + DUP_OFFSET)

#define EUP_1 memcpy((bool *) shmem.data() + EUP_OFFSET, new bool(1), sizeof(bool))
#define NUP_1 memcpy((bool *) shmem.data() + NUP_OFFSET, new bool(1), sizeof(bool))
#define DUP_1 memcpy((bool *) shmem.data() + DUP_OFFSET, new bool(1), sizeof(bool))
#define EUP_0 memcpy((bool *) shmem.data() + EUP_OFFSET, new bool(0), sizeof(bool))
#define NUP_0 memcpy((bool *) shmem.data() + NUP_OFFSET, new bool(0), sizeof(bool))
#define DUP_0 memcpy((bool *) shmem.data() + DUP_OFFSET, new bool(0), sizeof(bool))

#define PID * (new pid_t(getpid()))

#define SET_EPID memcpy((pid_t *) shmem.data() + EPID_OFFSET, &PID, sizeof(PID))
#define SET_NPID memcpy((pid_t *) shmem.data() + NPID_OFFSET, &PID, sizeof(PID))
#define SET_DPID memcpy((pid_t *) shmem.data() + DPID_OFFSET, &PID, sizeof(PID))
