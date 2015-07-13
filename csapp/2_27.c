#include <stdio.h>

int uadd_ok(unsigned x, unsigned y) {
    return (x + y) >= x;
}

int main() {
    int r;
    r = uadd_ok(-1, 6);
    printf("r: %d", r);
}
