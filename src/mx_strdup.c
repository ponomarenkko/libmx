#include "libmx.h"

char *mx_strdup(const char *s1){
    char *dupl = mx_strnew(mx_strlen(s1));
    mx_strcpy(dupl, s1);

    return dupl;
}
