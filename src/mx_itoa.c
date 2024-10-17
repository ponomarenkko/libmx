#include "libmx.h"

static int number_length(int number) {
    int len = 0;

    while (number) {
        number /= 10;
        len++;
    }
    return len;
}

char *mx_itoa(int number) {
    int length = number_length(number);
    int tmp = number;
    char *res = NULL;

    res = mx_strnew(length);
    if (number == 0) {
        return mx_strcpy(res, "0");
    }
    if (number == -2147483648) {
        return mx_strcpy(res, "-2147483648");
    }
    tmp = number;
    for (int i = 0; i < length; i++) {
        if (tmp < 0) {
            res[length] = '-';
            tmp = -tmp;
        }
        res[i] = (tmp % 10) + '0';
        tmp /= 10;
    }
    mx_str_reverse(res);
    return res;
}
