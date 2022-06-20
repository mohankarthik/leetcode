#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <float.h>

#define MAX_LEN 100

int atoi(const char *s) {
    // Preconditions
    if (s == NULL) return 0;

    const uint32_t n = (uint32_t)strlen(s);
    const bool isNegative = s[0] == '-';

    uint32_t i = isNegative ? 1u : 0u;
    int64_t answer = 0;
    for (; i < n; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return -1;
        }
        answer *= 10;
        answer += s[i] - '0';
        if (!isNegative && answer >= INT32_MAX) return INT32_MAX;
        if (isNegative && answer >= (INT32_MAX-1)) return INT32_MIN;
    }

    return (int32_t)(isNegative ? -answer : answer);
}

double atof(const char *s) {
    // Preconditions
    if (s == NULL) return 0;

    const uint32_t n = (uint32_t)strlen(s);
    const bool isNegative = s[0] == '-';

    uint32_t i = isNegative ? 1u : 0u;
    int decimalPlace = 0;
    double answer = 0.0;

    for (; i < n; i++) {
        if (s[i] == '.') {
            if (decimalPlace != 0) return 0.0;
            decimalPlace = 1;
        } else if (s[i] < '0' || s[i] > '9') {
            return 0.0;
        } else {
            if (decimalPlace == 0) {
                if (answer >= ((DBL_MAX/10) - s[i] - '0')) return (isNegative ? DBL_MAX : -DBL_MAX);
                answer *= 10.0;
                answer += s[i] - '0';
            } else {
                decimalPlace *= 10;
                answer += (s[i] - '0') / (double)decimalPlace;
            }
        }
    }

    return isNegative ? -answer : answer;
}

char *reverse(char *str, int len) {
    char ch;
    int i = 0;
    for (i = 0; i < (len/2); i++) {
        ch = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = ch;
    }
    return str;
}

char *itobase(int n, char *str, int maxlen, int base) {
    // Preconditions
    if (str == NULL) return NULL;

    const bool isNegative = n < 0;
    int i = 0;

    if (base != 10 && isNegative) return NULL;

    for (int i = 0; i < maxlen; i++) str[i] = '\0';
    if (isNegative) n = -n;

    while (n > 0) {
        if (i >= maxlen) return NULL;
        const int val = (n % base);
        str[i++] = (val<= 9) ? val + '0' : val + 'a' - 10;
        n /= base;
    }
    if (i >= maxlen) return NULL;
    if (isNegative) str[i++] = '-';

    if (i >= maxlen) return NULL;
    str[i] = (char)'\0';

    reverse(str, i);

    return str;
}

char *ftobin(double n, char *str, int maxlen, int decimals) {
    // Preconditions
    if (n < 0) return NULL;
    if (str == NULL) return NULL;

    int integral = (int)n;
    double frac = n - integral;
    int i = 0;

    while(integral > 0) {
        if (i >= maxlen) return NULL;
        str[i++] = (integral & 1) + '0';
        integral >>= 1;
    }
    reverse(str, i);
    if (frac == 0.0) return str;

    if ((i + decimals + 1)>= maxlen) return NULL;
    str[i++] = '.';
    while(decimals--) {
        frac *= 2.0;
        if (frac > 1.0) {
            str[i++] = '1';
            frac -= 1.0;
        } else {
            str[i++] = '0';
        }
    }

    return str;
}

int main(void) {
    char str[MAX_LEN];
    /*
    printf("%d\n", atoi("123"));
    printf("%d\n", atoi("-256"));
    printf("%d\n", atoi("asdf"));
    printf("%d\n", atoi("12341234545231"));
    printf("%d\n", atoi("-12341234545231"));
    */
    printf("%f\n", atof("-253.23"));

    /*
    printf("%s\n", itobase(-256, str, MAX_LEN, 10));
    printf("%s\n", itobase(-26, str, MAX_LEN, 10));
    printf("%s\n", itobase(16, str, MAX_LEN, 2));
    */
    
    /*
    printf("%s\n", ftobin(2.47, str, MAX_LEN, 5));
    printf("%s\n", ftobin(6.986, str, MAX_LEN, 8));
    */
}