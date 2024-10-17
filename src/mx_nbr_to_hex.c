#include "libmx.h"

static int num_len(unsigned long num) {
    int len1 = 0;

    while (num) {
        num /= 16;
        len1++;
    }
    return len1;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *num_char = NULL;
    unsigned long num = nbr;
    int len2 = num_len(nbr);
    int temp;

    num_char = malloc(len2 + 1);
    if (nbr == 0)
        return mx_strcpy(num_char, "0");

    num_char[len2] = '\0';

    while (num) {
        temp = num % 16;
        if (temp < 10) {
            num_char[--len2] = 48 + temp;        } else {
            num_char[--len2] = 87 + temp;
        }
        num /= 16;
    }

    return num_char;
}
