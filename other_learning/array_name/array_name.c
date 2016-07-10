//
// Created by duozhang on 2016/7/9.
//
#include <stdio.h>

void my_print(int* a);

int main() {
    int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    my_print(a);

    //printf("a: %d\n", (int) **a);
    //printf("a[0]: %d\n", a[0]);
    //printf("a[0][0]: %d\n", a[0][0]);
}

void my_print(int* a) {
    printf("p: %d\n", a);
}
