extern int buf[];

void swap() {
    int temp = buf[0];
    buf[0] = buf[1];
    buf[1] = temp;
}
