#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int index = 0;
    int sublength = 0;
    
    if (sub && str) {
        sublength = mx_strlen(sub);
        while (*str) {
            if (mx_strncmp(str, sub, sublength) == 0){
                return index;
            }
            index++;
            str++;
        }
        return -1;
    }
    return -2;
}
