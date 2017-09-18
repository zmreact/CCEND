#include "main.h"

int main(int argc, const char * argv[]) {
    while (true) {
        switch (state) {
            case encoder:
                break;
            case decoder:
                std::cout << "Received codes: \n";
                for (int i = 0; i < 16; i++) {
                    std::bitset<4> binval(* (pt_memA + i));
                    std::cout << binval << " ";
                }
                std::cout << "Decoding...\n";
                state == encoder;
            case ng:
                break;
        }
    }
    return 0;
}
