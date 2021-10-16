#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    int id;
    char name[20];
    struct room* next;
} room;

struct room createList() {
    room head;
    head.id = -1;
    strcpy(head.name, "top");
    head.next = NULL;
    return head;
}

/* function searches the list of room
 * return 0 if found
 * return -1 if not found
 */
room* searchList(room* head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            return head;
        }
        else {
            head = head->next;
        }
    }
    return NULL;
}

/**
 * Function adds a room at the end of list of rooms
 * returns 0 on success
 */
int addRoom(room* ptr, char name[]) {
    // room* ptr = head;
    // keeping track of last ID; (improve auto increment logic)
    int lastID = -1;
    // traverse till the last of the list
    while (ptr->next != NULL) {
        ptr = ptr->next;
        lastID = ptr->id;
    }
    ptr->next = (room*)(malloc(sizeof(room)));
    ptr->next->id = lastID + 1;
    strcpy(ptr->next->name, name);
    ptr->next->next = NULL;
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    //creating list
    room head = createList();

    //adding rooms
    room* ptr = &head;


    printf(addRoom(ptr, "pranav"));

    printf(addRoom(ptr, "acharya"));

    printf(addRoom(ptr, "appu"));

    printf(addRoom(ptr, "lord"));

    room** ptrptr = &ptr;

    // searching rooms
    room* rm = searchList(ptr, 2);
    printf("roomname : %s\n", rm->name);
    return 0;
}