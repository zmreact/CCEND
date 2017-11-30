#ifndef library_h
#define library_h

#if     defined __APPLE__ || defined __linux__
    #include <unistd.h>
#elif   defined _WIN32 || defined _WIN64
    #include <Windows.h>
#endif

void cpsleep(int sleep_ms);

#endif
