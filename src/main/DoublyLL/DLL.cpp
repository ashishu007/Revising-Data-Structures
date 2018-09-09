#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
};

// Given head pointer, insert a node at the beginning
void push(struct Node **head, int new_val) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> val = new_val;
    new_node -> next = *head;
    new_node -> prev = NULL;
    // if((*head) != NULL) {
    //     (*head) -> prev = new_node;
    // }
    (*head) = new_node;
}

// Given head pointer, insert a node at the end
void append(struct Node **head, int new_val) {

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *temp = *head;

    new_node -> val = new_val;
    new_node -> next = NULL;

    if (temp == NULL) {
        new_node -> prev = NULL;
        *head = new_node;
        return;
    }

    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    new_node -> prev = temp;
    temp -> next = new_node;
}

// Print the Linked List 
void printList(struct Node* node) {
    printf("NULL <-> ");
    while(node != NULL) {
        printf(" %d <->", node -> val);
        node = node -> next;
    }
    printf(" NULL");
}

// Given a node, insert another node after it
void insertNext(struct Node* node, int new_val) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        cout<<"Given pointer cannot be NULL"<<endl;
        return;
    }
    new_node -> val = new_val;
    new_node -> next = node -> next;
    new_node -> prev = node;
    node -> next = new_node;
}

// Given a node, insert a node before it
void insertPrev(struct Node* node, int new_val) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        cout<<"Given pointer cannot be NULL"<<endl;
        return;
    }
    printf("Befor node->prev->val = %d \n", node->prev->val);
    new_node -> val = new_val;
    printf("%d \t %d \n", new_node->val, node->val);
    new_node -> prev = node -> prev;
    printf("new_node->prev->val = %d \n", new_node->prev->val);
    new_node -> next = node;
    printf("new_node->next->val = %d \n", new_node->next->val);
    node -> prev = new_node;
    printf("After node->prev->val = %d \n", node->prev->val);
}

void deleteKey(struct Node** head, int key) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp -> val == key) {
        *head = temp -> next;
        free(temp);
        return;
    } 

    while(temp -> next != NULL && key != temp -> val) {
        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL) {
        printf("Key not found \n");
        return;
    }

    if (temp -> next == NULL) {
        temp -> prev -> next = NULL;
        free(temp);
        return;
    }

    // prev -> next = temp -> next;
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = prev;
    free(temp);
}

int main() {

    struct Node *node = NULL;
    
    append(&node, 0);
    push(&node, 1);
    push(&node, 2);
    push(&node, 3);
    append(&node, 4);
    
    // printList(node);
    // cout<<endl;
    // cout<<node->next->next->val<<endl;
    // cout<<node->next->next->prev->val<<endl;
    
    // insertPrev(node->next->next, 6);

    // printList(node);
    // cout<<endl;
    // cout<<node->next->next->val<<endl;

    insertNext(node->next->next, 5);
    printList(node);
    cout<<endl;

    deleteKey(&node, 4);
    printList(node);

    return 0;
}