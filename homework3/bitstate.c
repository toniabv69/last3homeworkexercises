#include <stdio.h>
#include "bitstate.h"

static unsigned int bitstate = 0;

int setbit(int bit_index) {
    if(bit_index < 0 || bit_index > 31) return -1;
    bitstate = bitstate | (1 << bit_index);
    return 0; 
}

int unsetbit(int bit_index) {
    if(bit_index < 0 || bit_index > 31) return -1;
    bitstate = ~bitstate;
    bitstate = bitstate | (1 << bit_index);
    bitstate = ~bitstate;
    return 0;
}

int togglebit(int bit_index) {
    if(bit_index < 0 || bit_index > 31) return -1;
    bitstate = bitstate ^ (1 << bit_index);
    return 0;
}

int isbitset(int bit_index) {
    if(bit_index < 0 || bit_index > 31) return -1;
    if((bitstate & (1 << bit_index)) == (1 << bit_index)) return 1;
    else return 0;
}

int getbitstate() {
    return bitstate;
}
