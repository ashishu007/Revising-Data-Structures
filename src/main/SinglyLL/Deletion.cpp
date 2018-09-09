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

void deleteKey(struct Node **head, int key) {
    struct Node* temp = *head, *prev;

    if (temp != NULL && temp -> val == key) {
        *head = temp -> nxt;
        free(temp);
        return;
    }

    while(temp != NULL && temp -> val != key) {
        prev = temp;
        temp = temp -> nxt;
    }

    if (temp == NULL) {
        printf("Key not found \n");
        return;
    }

    prev -> nxt = temp -> nxt;
    free(temp);
}

void deletePos(struct Node **head, int pos) {
    struct Node *temp = *head, *prev;
    int ctr = 0;

    if (pos == 0) {
        *head = temp -> nxt;
        free(temp);
        return;
    }

    while(temp != NULL && ctr != pos) {
        prev = temp;
        temp = temp -> nxt;
        ctr += 1;
    }
    // printf("ctr = %d \t pos = %d \n", ctr, pos);

    if(temp == NULL) {
        printf("Position does not exist \n");
        return;
    }

    prev -> nxt = temp -> nxt;
    free(temp);
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
    // printList(head);
    // cout<<"\n";

    first_pos(&head, 2);
    // printList(head);
    // cout<<"\n";

    first_pos(&head, 3);
    // printList(head);
    // cout<<"\n";

    insert_pos(head->nxt, 4);
    // printList(head);
    // cout<<"\n";

    insert_pos(head, 5);
    printList(head);
    cout<<"\n";

    deleteKey(&head, 1);
    printList(head);
    cout<<endl;

    deletePos(&head, 1);
    printList(head);
    cout<<endl;

    deletePos(&head, 5);
    printList(head);
    cout<<endl;

    return 0;
}