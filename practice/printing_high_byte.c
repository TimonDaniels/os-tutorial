#include <stdio.h>

void main() {
    unsigned short a = 0x0111;
    unsigned char high_byte = a >> 8;
    printf("High byte: 0x%02x\n", high_byte);
};