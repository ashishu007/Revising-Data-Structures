#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node {
    int val;
    struct Node *nxt;
};

void first_pos(struct Node** head, int new_val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> val = new_val;
    new_node -> nxt = (*head);
    (*head) = new_node;
}

void insert_pos(struct Node* prev, int new_val) {
    if (prev == NULL) {
        printf("Previous node can't be NULL");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> val = new_val;
    new_node -> nxt = prev -> nxt;
    prev -> nxt = new_node;
}

void last_pos(struct Node** head, int new_val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;

    new_node -> val = new_val;
    new_node -> nxt = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    while(last -> nxt != NULL){
        last = last -> nxt;
    }
    
    last -> nxt = new_node;
}

void printList(struct Node* node) {
    while(node != NULL) {
        if (node -> nxt == NULL) {
            printf("%d", node -> val);
            node = node -> nxt;
        }
        else {
            printf("%d -> ", node -> val);
            node = node -> nxt;
        }
    }
}

int main() {
    struct Node* head = NULL;

    last_pos(&head, 1);
    printList(head);
    cout<<"\n";

    first_pos(&head, 2);
    printList(head);
    cout<<"\n";

    first_pos(&head, 3);
    printList(head);
    cout<<"\n";

    insert_pos(head->nxt, 4);
    printList(head);
    cout<<"\n";

    insert_pos(head, 5);
    printList(head);
    cout<<"\n";

    return 0;
}