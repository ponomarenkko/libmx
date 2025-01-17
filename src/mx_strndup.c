#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){
    char *dupl = NULL;
    size_t len = mx_strlen(s1);

    if (n < len){ 
    len = n;
    }

    dupl = mx_strnew(len);
    mx_strncpy(dupl, s1, len);
    
    return dupl;
}
