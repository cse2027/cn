#include <stdio.h>
#include <string.h>

#define CRC_DEGREE 16
#define CRC_POLY 0x18005  // Corrected from '0 x18005' and added proper hex literal

// Convert binary string to unsigned long
static unsigned long binstr_to_ul(const char *s) {
    unsigned long v = 0;
    for (; *s; ++s) {
        v = (v << 1) | (*s == '1');
    }
    return v;
}

// Convert unsigned long to binary string
static void ul_to_binstr(unsigned long v, int len, char *out) {
    out[len] = '\0';
    for (int i = len - 1; i >= 0; --i) {
        out[i] = (v & 1) ? '1' : '0';
        v >>= 1;
    }
}

int main(void) {
    char msg[512];
    scanf("%511s", msg);  // Removed extra spaces

    int mlen = (int)strlen(msg);
    unsigned long dividend = binstr_to_ul(msg) << CRC_DEGREE;
    int total_bits = mlen + CRC_DEGREE;
    int genw = CRC_DEGREE + 1;
    unsigned long top = 1UL << (total_bits - 1);

    for (int i = 0; i <= total_bits - genw; ++i) {
        unsigned long cur = top >> i;
        if (dividend & cur) {
            unsigned long aligned = (unsigned long)CRC_POLY << (total_bits - genw - i);
            dividend ^= aligned;
        }
    }

    unsigned long crc = dividend & ((1UL << CRC_DEGREE) - 1);
    char out[CRC_DEGREE + 1];
    ul_to_binstr(crc, CRC_DEGREE, out);

    printf("CRC-16 (IBM/ANSI): %s\n", out);
    printf("Codeword: %s%s\n", msg, out);

    return 0;
}
