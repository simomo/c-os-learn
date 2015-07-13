# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"
void swap();
void print_array(int* arr, int arr_size);

int buf[2] = {1, 2};

int main() {
    swap();
    print_array(buf, 2);
}
