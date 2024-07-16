#ifndef VARLENGTH_H
#define VARLENGTH_H

void toVarInt(int integer, void (*consumer)(char));
int fromVarInt(char* chars);

#endif
