#include <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})



//TODO: iterator whole list
#define ITER_LIST(


struct list_head {
    struct list_head* prev;
    struct list_head* next;
};

void inline init_list(list_head* list) {
    list->prev = list;
    list->next = list;
}

//TODO: Insert item at head
void inline insert_list_head(list_head* list, list_head* item) {
    item->prev = list;
    item->next = list->next;
    list->next = item;
}

//TODO: Insert item at tail
void inline insert_list_tail(list_head* list, list_head* item) {
    item->prev = list->prev;
    item->next = list;
    list->prev = item;
}

//TODO: remove one item
void inline remove_list(list_head* list, list_head* item) {
    item->prev->next = item->next;
    item->next->prev = item->prev;
}

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
