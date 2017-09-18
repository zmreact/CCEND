#include <QtCore/qsharedmemory.h>

int memA[16];
int memB[16];
int * pt_memA = &memA[0];
int * pt_memB = &memB[0];

bool ng_isup = false;
enum states {encoder, ng, decoder};
states state;

QSharedMemory mem;
