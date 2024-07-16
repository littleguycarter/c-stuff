#include<stdlib.h>
#include<stdio.h>
#include "varlength.h"

void toVarInt(int integer, void (*consumer)(char)) {
    unsigned int properInteger = integer;

    while (true) {
        if ((properInteger & ~0x7F) == 0) {
            (*consumer)((char) properInteger);
            return;
        }

        (*consumer)((char) ((properInteger & 0x7F) | 0x80));
        properInteger >>= 7;
    }
}


int fromVarInt(char* chars) {
    int index = 0;
    int integer = 0;

    while (true) {
        unsigned int current = chars[index];

        if ((current & 0x80) == 0) {
            integer |= (current) << (index * 7);
            break;
        }

        integer |= (current & 0x7F) << (index * 7);
        index++;
    }

    return integer;
}
