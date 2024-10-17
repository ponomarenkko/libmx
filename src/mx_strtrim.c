#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str){
        return NULL;
    }
    while (mx_isspace(*str)){
        str++;
    }
    int lenght = mx_strlen(str);

    while (mx_isspace(str[lenght - 1])){
        lenght--;
    }

    return mx_strndup(str, lenght);
}
