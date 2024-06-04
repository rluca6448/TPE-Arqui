#include <string.h>

int strcmp(char *s1, char *s2) {
    const unsigned char *p1 = ( const unsigned char * )s1;
    const unsigned char *p2 = ( const unsigned char * )s2;

    while ( *p1 && *p1 == *p2 ) ++p1, ++p2;

    return ( *p1 > *p2 ) - ( *p2  > *p1 );
}

int strlen(const char * str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}