#include "libmx.h"

static int get_word_length(const char *s, char c) {
    int length = 0;
    char *copy_s = (char *)s;
    while ((*copy_s != c) && (*copy_s != '\0')) {
        length++;
        copy_s++;
    }
    return length;
}

char **mx_strsplit(const char *s, char c) {
    int len = 0;
    int i = 0;
    char **arr = NULL;
    if (!s) {
        return NULL;
    }
    arr = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            len = get_word_length(s, c);
            arr[i] = mx_strndup(s, len);
            s += len;
            i++;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    return arr;
}

