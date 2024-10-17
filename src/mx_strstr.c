#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    if (haystack == NULL || needle == NULL)
        return NULL;

    int needle_len = mx_strlen(needle);

    if (needle_len == 0)
        return (char *)haystack;
    
    while (*haystack != '\0')
    {
        if (*haystack == *needle)
        {
            if (mx_strncmp(haystack, needle, needle_len) == 0)
                return (char *)haystack;
        }
        haystack++;
    }
    
    return NULL;
}
