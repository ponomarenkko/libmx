#include "libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL)
        return -1;
    
    if (mx_strlen(sub) == 0)
        return 0;

    const char *needle = sub;
    int total = 0;
    const char *ptr = str;

    while ((ptr = mx_strstr(ptr, needle)) != 0)
    {
        ptr += mx_strlen(needle);
        total++;
    }
    
    return total;
}
