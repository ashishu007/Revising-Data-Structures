#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void first(struct Node **head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head);
    (*head) = new_node;
}

void position(struct Node *prev, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (prev == NULL) {
        cout<<"Previous cannot be empty"<<endl;
        return;
    }
    new_node -> data = new_data;
    new_node -> next = prev -> next;
    prev -> next = new_node;
}

void last(struct Node **head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;

    new_node -> data = new_data;
    new_node -> next = NULL;

    if (last == NULL) {
        *head = new_node;
        return;
    }
    new_node -> data = new_data;
    while(last -> next != NULL) {
        last = last -> next;
    }
    last -> next = new_node;
}

void deleteKey(struct Node **head, int key) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && key == temp -> data) {
        *head = temp -> next;
        free(temp);
        return;
    }

    while(temp != NULL && key != temp -> data) {
        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL) {
        printf("Key not found \n");
        return;
    }

    prev -> next = temp -> next;
    free(temp);
}

void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d -> ", node -> data);
        node = node -> next;
    }
}

int main()
{
    struct Node *node = NULL;

    last(&node, 1);
    // printList(node);

    // cout<<endl;

    position(node, 2);
    printList(node);

    cout<<endl;

    deleteKey(&node, 21);
    printList(node);

    return 0;
}
