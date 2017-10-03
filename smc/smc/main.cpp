// Shared memory cleaner
#include <iostream>
#include "../../include/shared.h"
#include <QtCore/qsystemsemaphore.h>
using namespace std;


int main(int argc, const char * argv[]) {
    QSystemSemaphore sema("/sema", 1);
    
    sema.acquire();
    if (owed_shmem.attach()) {
        cout << "Cleaning if unattached shared memory is present..." << endl;
        owed_shmem.detach();
        cout << "OK" << endl << endl;
    }
    else {
        cout << "Nothing to clean" << endl << endl;
    }
    sema.release();
    
    return 0;
}
