#include "library.h"

void cpsleep(int sleep_ms) {
#ifdef  defined __APPLE__ || defined __linux__
    usleep(sleep_ms * 1000);
#elif   defined _WIN32 || defined _WIN64
    Sleep(sleep_ms);
#endif
}
