// Shared memory realization

#include <unistd.h>
#include <QtCore/qsharedmemory.h>
#include <QtCore/qsystemsemaphore.h>

static QSystemSemaphore     sema("/sema", 1);
static QSharedMemory        owed_shmem("/shmem");
static QSharedMemory        shmem("/shmem");

void shmem_alloc_and_clean();

#define TURN_OFFSET         0
#define E_STATE_OFFSET      4
#define E_PID_OFFSET        5
#define N_STATE_OFFSET      9
#define N_PID_OFFSET        10
#define D_STATE_OFFSET      14
#define D_PID_OFFSET        15
#define D_OFFSET            19
#define D_SIZE              64

#define TURN_PTR                    ((turns *) shmem.data() + TURN_OFFSET)
#define E_STATE_PTR                 ((bool *) shmem.data() + E_STATE_OFFSET)
#define N_STATE_PTR                 ((bool *) shmem.data() + N_STATE_OFFSET)
#define D_STATE_PTR                 ((bool *) shmem.data() + D_STATE_OFFSET)

#define TURN                        *TURN_PTR
#define E_STATE                     *E_STATE_PTR
#define N_STATE                     *N_STATE_PTR
#define D_STATE                     *D_STATE_PTR

#define E_PID_PTR                   ((pid_t *) shmem.data() + E_PID_OFFSET)
#define N_PID_PTR                   ((pid_t *) shmem.data() + N_PID_OFFSET)
#define D_PID_PTR                   ((pid_t *) shmem.data() + D_PID_OFFSET)

#define E_PID                       *E_PID_PTR
#define N_PID                       *N_PID_PTR
#define D_PID                       *D_PID_PTR

enum turns {E, N, D};
static const turns E_TURN = E;
static const turns N_TURN = N;
static const turns D_TURN = D;

static const bool UP =      true;
static const bool DOWN =    false;

static pid_t * PID (new pid_t(getpid()));

#define GIVE_E_TURN                 memcpy(TURN_PTR, &E_TURN, sizeof(E_TURN))
#define GIVE_N_TURN                 memcpy(TURN_PTR, &N_TURN, sizeof(N_TURN))
#define GIVE_D_TURN                 memcpy(TURN_PTR, &D_TURN, sizeof(D_TURN))


#define SET_E_UP                    memcpy(E_STATE_PTR, &UP, sizeof(UP))
#define SET_N_UP                    memcpy(N_STATE_PTR, &UP, sizeof(UP))
#define SET_D_UP                    memcpy(D_STATE_PTR, &UP, sizeof(UP))
#define SET_E_DOWN                  memcpy(E_STATE_PTR, &DOWN, sizeof(DOWN))
#define SET_N_DOWN                  memcpy(N_STATE_PTR, &DOWN, sizeof(DOWN))
#define SET_D_DOWN                  memcpy(D_STATE_PTR, &DOWN, sizeof(DOWN))

#define SET_ENCODER_PID             memcpy(E_PID_PTR, &PID, sizeof(PID))
#define SET_NOISEGENERATOR_PID      memcpy(N_PID_PTR, &PID, sizeof(PID))
#define SET_DECODER_PID             memcpy(D_PID_PTR, &PID, sizeof(PID))


