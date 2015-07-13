#include <stdio.h>

int tadd_ok(int x, int y) {
    if (x > 0 && y > 0) {
        return (x + y) > 0;
    } else if (x < 0 && y < 0) {
        return (x + y) < 0;
    } else {
        return 1;
    }
}


int main() {
    int r = tadd_ok(2147483646, 1);
    printf("r: %d\n", r);
}
