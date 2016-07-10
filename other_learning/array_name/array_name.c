//
// Created by duozhang on 2016/7/9.
//
#include <stdio.h>


int main() {
    int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    printf("a: %d\n", (int) **a);
    printf("a[0]: %d\n", a[0]);
    printf("a[0][0]: %d\n", a[0][0]);
}

