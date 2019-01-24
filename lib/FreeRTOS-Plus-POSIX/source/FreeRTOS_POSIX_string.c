
#include <stddef.h>

void *memchr(const void *str, int c, size_t n)
{
    const char *s = (const char *)str;

    for(int i = 0; i < n; i++) {
        char a = *(s + i);
        if(a == c) {
            return (void *)(s + i);
        }
    }

    return (void *)NULL;
}

void *memcpy(void *dist, const void *src, size_t n)
{
    const char *s = (const char *)src;
    char *d = ((char *)d) + n;

    while(n--) {
        *d = *(s + n);
        d--;
    }
    
    return dist;
}

void *memset(void *str, int c, size_t n)
{
    char *s = (char *)str + n;

    while(n--) {
        *s = c;
        s--;
    }

    return str;
}

char *strcat(char *dest, const char *src)
{
    size_t len = strlen(src) - 1;
    char *p = dest + strlen(dest) + len;

    while(len-- > 0) {
        *p-- = *(src + len - 1);
    }
    
    return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
    char *p = dest + strlen(dest) + n;

    while(n-- > 0) {
        *p-- = *(src + n - 1);
    }
    
    return dest;
}
