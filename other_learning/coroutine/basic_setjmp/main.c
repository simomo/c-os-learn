/*
 * Basic idea:
 * A -> B -> C
 * ^         |
 * |  jump   V
 * +---------+
 */
#include <stdio.h>
#include <setjmp.h>

jmp_buf jmp_mark;

void B(void);
void C(void);

int main(void) {
    if (setjmp(jmp_mark) == 0) {
        printf("I will be back\n");
        B();
    } else {
        printf("I'm back\n");
    }

    return 1;
}

void B(void) {
    printf("I'm B\n");
    C();
}

void C(void) {
    printf("I'm C\n");
    longjmp(jmp_mark, 1);
}
