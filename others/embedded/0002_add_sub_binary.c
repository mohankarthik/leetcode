#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

uint32_t addBinOp1(uint32_t op1, uint32_t op2) {
    uint32_t carry = 0;
    while(op2 != 0u) {
        carry = op1 & op2;
        op1 ^= op2;
        op2 = carry << 1;
    }
    return op1;
}

int32_t subBinOp(uint32_t op1, uint32_t op2) {
    uint32_t borrow;
    while(op2 != 0u) {
        borrow = (~op1) & op2;
        op1 ^= op1 ^ op2;
        op2 = borrow << 1;
    }
    return (int32_t)op1;
}

int main(void) {
    printf("%d\n", addBinOp1(45, 27));
    printf("%d\n", subBinOp(13, 29));
    return 0;
}