#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    static char *remainder = NULL;
    char *buffer = malloc(buf_size);
    int total_len = 0;
    int bytes_read;
    int i, j;
    
    if (fd < 0 || !lineptr || buf_size <= 0 || !buffer)
    {
        free(buffer);
        return -2;
    }

    *lineptr = NULL;
    
    if (remainder)
    {
        for (i = 0; remainder[i] != '\0'; i++)
        {
            if (remainder[i] == delim)
            {
                remainder[i] = '\0';
                *lineptr = malloc(i + 1);
                if (!*lineptr)
                {
                    free(buffer);
                    return -2;
                }

                for (j = 0; j < i; j++)
                    (*lineptr)[j] = remainder[j];
                
                (*lineptr)[i] = '\0';

                char *new_remainder = malloc(mx_strlen(remainder + i + 1) + 1);
                if (!new_remainder)
                {
                    free(buffer);
                    free(*lineptr);
                    return -2;
                }

                for (j = 0; remainder[i + 1 + j] != '\0'; j++)
                    new_remainder[j] = remainder[i + 1 + j];
                
                new_remainder[j] = '\0';
                free(remainder);
                remainder = new_remainder;
                free(buffer);
                return i;
            }
        }

        *lineptr = malloc(i + 1);
        if (!*lineptr)
        {
            free(buffer);
            return -2;
        }

        for (j = 0; j < i; j++) 
            (*lineptr)[j] = remainder[j];
        
        (*lineptr)[i] = '\0';
        total_len = i;
        free(remainder);
        remainder = NULL;
    }

    while ((bytes_read = read(fd, buffer, buf_size)) > 0)
    {
        for (i = 0; i < bytes_read; i++)
        {
            if (buffer[i] == delim) {

                *lineptr = mx_realloc(*lineptr, total_len + i + 1);
                if (!*lineptr)
                {
                    free(buffer);
                    return -2;
                }

                for (j = 0; j < i; j++)
                    (*lineptr)[total_len + j] = buffer[j];

                (*lineptr)[total_len + i] = '\0';
                
                remainder = malloc(bytes_read - i);
                if (!remainder)
                {
                    free(buffer);
                    free(*lineptr);
                    return -2; 
                }

                for (j = 0; j < bytes_read - i - 1; j++)
                    remainder[j] = buffer[i + 1 + j];

                remainder[bytes_read - i - 1] = '\0';
                free(buffer);
                return total_len + i;
            }
        }

        *lineptr = mx_realloc(*lineptr, total_len + bytes_read + 1);
        if (!*lineptr)
        {
            free(buffer);
            return -2;
        }
        
        for (j = 0; j < bytes_read; j++) 
            (*lineptr)[total_len + j] = buffer[j];

        total_len += bytes_read;
        (*lineptr)[total_len] = '\0';
    }

    free(buffer);
    
    if (bytes_read == 0 && total_len > 0)
        return total_len;

    return -1;
}
