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
#define D_SIZE 16

enum states {E, N, D};
static const states E_STATE = E;
static const states N_STATE = N;
static const states D_STATE = D;

static const bool UP = true;
static const bool DOWN = false;

#define SWITCH_TO_E_STATE memcpy((states *) shmem.data() + STATE_OFFSET, &E_STATE, sizeof(E_STATE))
#define SWITCH_TO_N_STATE memcpy((states *) shmem.data() + STATE_OFFSET, &N_STATE, sizeof(N_STATE))
#define SWITCH_TO_D_STATE memcpy((states *) shmem.data() + STATE_OFFSET, &D_STATE, sizeof(D_STATE))

#define STATE * ((states *) shmem.data() + STATE_OFFSET)
#define EUP * ((bool *) shmem.data() + EUP_OFFSET)
#define NUP * ((bool *) shmem.data() + NUP_OFFSET)
#define DUP * ((bool *) shmem.data() + DUP_OFFSET)

#define EUP_1 memcpy((bool *) shmem.data() + EUP_OFFSET, &UP, sizeof(UP))
#define NUP_1 memcpy((bool *) shmem.data() + NUP_OFFSET, &UP, sizeof(UP))
#define DUP_1 memcpy((bool *) shmem.data() + DUP_OFFSET, &UP, sizeof(UP))
#define EUP_0 memcpy((bool *) shmem.data() + EUP_OFFSET, &DOWN, sizeof(DOWN))
#define NUP_0 memcpy((bool *) shmem.data() + NUP_OFFSET, &DOWN), sizeof(DOWN))
#define DUP_0 memcpy((bool *) shmem.data() + DUP_OFFSET, &DOWN, sizeof(DOWN))

#define PID * (new pid_t(getpid()))

#define SET_ENCODER_PID memcpy((pid_t *) shmem.data() + EPID_OFFSET, &PID, sizeof(PID))
#define SET_NOISEGENERATOR_PID memcpy((pid_t *) shmem.data() + NPID_OFFSET, &PID, sizeof(PID))
#define SET_DECODER_PID memcpy((pid_t *) shmem.data() + DPID_OFFSET, &PID, sizeof(PID))
