#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    if (big_len >= little_len && big_len > 0 && little_len > 0)
    {
        unsigned char *big_p = (unsigned char *)big;
        unsigned char *little_p = (unsigned char *)little;

        for (size_t i = 0; i <= big_len - little_len; i++)
        {
            if (mx_memcmp(big_p + i, little_p, little_len) == 0)
                return big_p + i;
        }
    }
    
    return NULL;
}
