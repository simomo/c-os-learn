#include <stdio.h>

//extern char* p;
char p[];

void main() {
    printf("%c", *p);
}
