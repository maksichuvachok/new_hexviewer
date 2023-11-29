#include <stdio.h>

char *dec2hex(char s, size_t size) {
    static const char hexnum[] = "0123456789ABCDEF"; 
    static char symbol[3] = { '0', '0', 0 };

    symbol[0] = hexnum[(s >> 4) & 0x0F];
    symbol[1] = hexnum[s & 0x0F];

    return symbol;
}

char *dec2bin(char s, size_t size) {
    const char binarynum[] = "01";
    static char binary[9] = "--------";
    binary[8] = '\0';

    for (int i = 7; i >= 0; i--)
    {
        binary[7 - i] = binarynum[(s >> i) & 1];
    }

    return binary;
}

char *dec2oct(char s, size_t size) {
    static const char octalnum[] = "01234567";
    static char octal[4] = "---";
    octal[3] = '\0';

    for (int i = 2; i >= 0; i--)
    {
        octal[2 - i] = octalnum[s >> (3 * i) & 0x07];
    }

    return octal;
}