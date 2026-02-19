#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> g_firstTuringMachine = {
    /* State x */   /*When 0        When 1*/
    /* State 0 */   {"0 0 R",       "1 1 L",},
    /* State 1 */   {"10 1 R",      "1 1 L",},
    /* State 10 */  {"1010 0 R",    "11 0 R",},
    /* State 11 */  {"100 0 R",     "11 1 R",},
    /* State 100 */ {"100 0 R",     "101 0 R",},
    /* State 101 */ {"111 0 L",     "110 1 L",},
    /* State 110 */ {"110 0 L",     "1 1 L",},
    /* State 111 */ {"111 0 L",     "1000 1 L",},
    /* State 1000 */{"1001 0 L",    "1000 1 L",},
    /* State 1001 */{"10 0 L",      "1 1 L",},
    /* State 1010 */{"0 0 STOP",    "1010 1 R",},
};

int main() {
    std::cout << "Turing Machine - The Emperor's New Mind" << std::endl;
    std::cout << "Project initialized successfully!" << std::endl;
    return 0;
}
