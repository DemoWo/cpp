#include "ram.h"

int buffer[8];

void write(int pos, int value){
    buffer[pos] = value;
}

int read (int x) {
    return buffer [x];
}