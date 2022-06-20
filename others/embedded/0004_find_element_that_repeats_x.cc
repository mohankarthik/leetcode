#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#define MAX_REPATS  10

int findElementThatRepeatsX(const uint32_t *arr, int findRepeat, int ignoreRepeat) {
    // Preconditions
    assert(arr != NULL);
    assert(findRepeat < MAX_REPATS);
    assert(ignoreRepeat < MAX_REPATS);
    
    int repeats[MAX_REPATS];

}