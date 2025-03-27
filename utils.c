#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #define CLEAR "cls"
    #define PAUSE "pause"
#else
    #define CLEAR "clear"
    #define PAUSE "read -p 'Press enter to continue...'"
#endif
#include "utils.h"

void clearScreen() {
    system(CLEAR);
}

void pauseProgram() {
    system(PAUSE);
}

