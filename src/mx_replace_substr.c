#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace)
        return NULL;

    if (mx_strlen(str) == 0)
        return mx_strnew(0);

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int number_of_substr = mx_count_substr(str, sub);

    int new_len = str_len + number_of_substr * (replace_len - sub_len);

    char *res = mx_strnew(new_len);

    const char *temp = str;
    char *res_ptr = res;
    while (*temp)
    {
        const char *sub_ptr = mx_strstr(temp, sub);
        if (sub_ptr)
        {
            int copy_len = sub_ptr - temp;
            mx_strncpy(res_ptr, temp, copy_len);
            res_ptr += copy_len;

            mx_strcpy(res_ptr, replace);
            res_ptr += replace_len;

            temp = sub_ptr + sub_len;
        }
        else
        {
            mx_strcpy(res_ptr, temp);
            break;
        }
    }

    return res;
}
