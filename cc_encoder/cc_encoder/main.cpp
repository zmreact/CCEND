#include "main.h"

#define UNIVERSITY "MTUCI"
#define STGROUP "BSU1401"
#define DEVELOPERS "Denis Petuhov, Kaledina Anastasija, Korotygin Aleksandr, Ezhova Elena, Krasnov Kirill"

int main(int argc, const char * argv[]) {
    while (true) {
        switch (state) {
            case encoder:
                printf("University: %s\nStudent group: %s\nDevelopers: %s\n", UNIVERSITY, STGROUP, DEVELOPERS);
                
                std::cout << "\n" << "Source bit-codes: " << "\n";
                for (int i = 0; i < 16; i++) {
                    memA[i] = i;
                    mem.lock();
                    memcpy(mem.data(), &i, sizeof(i));
                    mem.unlock();
                }
                for (int i = 0; i < 16; i++) {
                    std::cout << std::bitset<4>(* (pt_memA + i)) << " ";
                }
                std::cout << "\n";
                std::cout << "\n" << "Generating code (7, 3) noise-free codes..." << "\n";
                std::cout << "\n" << "Parent polynom: " << std::bitset<4>(polynom) << "\n";
                std::cout << "Sending..." << "\n";
                if (ng_isup) state = ng;
                if (ng_isup == false) state = decoder;
                break;
            case decoder:
                break;
            case ng:
                break;
        }
    }
    return 0;
}
