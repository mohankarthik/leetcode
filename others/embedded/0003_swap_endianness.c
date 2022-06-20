#include <stdint.h>
#include <stdio.h>

#define SWAP_ENDIAN32(x) (\
    (x & 0x000000FFu) << 24U \
    | (x & 0x0000FF00u) << 8U \
    | (x & 0x00FF0000u) >> 8U \
    | (x & 0xFF000000u) >> 24U)

int main(void) {
    uint32_t val = 0x12345678U;
    printf("0x%x\nlittle Endian to big: 0x%x\n", val, SWAP_ENDIAN32(val));
}
