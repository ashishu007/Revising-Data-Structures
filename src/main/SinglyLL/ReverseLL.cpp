#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node {
    int val;
    struct Node *nxt;
};

void push(struct Node** head, int new_val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> val = new_val;
    new_node -> nxt = (*head);
    (*head) = new_node;
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

void reverseList(struct Node** head) {
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while(curr != NULL) {
        next = curr -> nxt;
        curr -> nxt = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    printList(head);
    cout<<endl;
    reverseList(&head);
    printList(head);

    return 0;
}