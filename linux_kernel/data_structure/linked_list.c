#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})


struct list_head {
    struct list_head* prev;
    struct list_head* next;
};

struct User {
    int id;
    char* name;

    struct list_head* list;
};

void print_user (struct User * p_u) {
    printf("id %d, name %s\n", p_u->id, p_u->name);
}

int main () {
    struct User user = {.id = 1, .name = "test"};
    struct User* p_u = &user;
    print_user(&user);

    return 1;
}
