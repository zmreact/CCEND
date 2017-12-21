#ifndef library_h
#define library_h

#if     defined __APPLE__ || defined __linux__
    #include <unistd.h>
    #include <stdio.h>
#elif   defined _WIN32 || defined _WIN64
    #include <Windows.h>
    #include <cstdio>
#endif

#define flush fseek(stdin, 0, SEEK_END)

void cpsleep(int sleep_ms);
void print_press_enter();

#endif
