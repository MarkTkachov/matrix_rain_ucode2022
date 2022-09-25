#include "../inc/header.h"

uchar *mx_ustrnew(const int size) {
    if (size < 0) return NULL;
    uchar *str = malloc(sizeof(uchar) * (size + 1));
    if (str == NULL) return NULL;
    for (int i = 0; i <= size; i++) {
        str[i] = 0;
    }
    return str;
}

int mx_ustrlen(const uchar *s) {
    int i = 0;
    while (s[i] != 0) {
        i++;
    }
    return i;  
}

uchar *mx_ustrjoin(uchar const *s1, uchar const *s2) {
    if (s1 == NULL && s2 == NULL) return NULL;
    if (s1 == NULL && s2 != NULL) {
        uchar *res = mx_ustrdup(s2);
        if (res == NULL) return NULL;
        return res;
    }
    if (s1 != NULL && s2 == NULL) {
        uchar *res = mx_ustrdup(s1);
        if (res == NULL) return NULL;
        return res;
    }

    uchar *res = mx_ustrnew(mx_ustrlen(s1) + mx_ustrlen(s2));
    if (res == NULL) return NULL;

    mx_ustrcpy(res, s1);
    mx_ustrcpy(res + mx_ustrlen(res), s2);

    return res;
}

uchar *mx_ustrdup(const uchar *str) {
    int len = mx_ustrlen(str);
    uchar *duplicate = mx_ustrnew(len);
    if (duplicate == NULL) return NULL;

    mx_ustrcpy(duplicate, str);
    return duplicate;
}

uchar *mx_ustrcpy(uchar *dst, const uchar *src) {
    int i = 0;
    while (src[i] != 0) {
        dst[i] = src[i];
        i++;
    }
    while (dst[i] != 0) {
        dst[i] = 0;
        i++;
    }
    return dst;
}
