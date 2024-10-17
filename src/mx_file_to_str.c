#include "libmx.h"

char *mx_file_to_str(const char *file)
{
    if (file == NULL)
        return NULL;

    int file_open = open(file, O_RDONLY);
    if (file_open < 0)
        return NULL;
    
    int len = 0;
    char buffer;
    while (read(file_open, &buffer, 1))
        len++;

    if (close(file_open) < 0)
        return NULL;

    file_open = open(file, O_RDONLY);
    if (file_open < 0)
        return NULL;

    char *res = mx_strnew(len);
    if (res == NULL)
    {
        close(file_open);
        return NULL;
    }

    if (read(file_open, res, len) != len)
    {
        close(file_open);
        free(res);
        return NULL;
    }

    if (close(file_open) < 0)
    {
        free(res);
        return NULL;
    }
    
    return res;
}
