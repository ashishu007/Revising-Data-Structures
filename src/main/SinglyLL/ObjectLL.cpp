#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class LinkedList {
    private:
        struct Node* new_node;
    public:
        LinkedList() {
            new_node = (struct Node*) malloc(sizeof(struct Node));
        }

        void push(struct Node** head, int val) {
            new_node -> data = val;
            new_node -> next = *head;
            *head = new_node;
        }

        void printList(struct Node *node) {
            while(node != NULL) {
                cout<<node -> data<<"->";
                node = node -> next;
            }
        }
};

int main()
{
    LinkedList ll;
    struct Node* head = NULL;
    ll.push(&head, 1);
    ll.push(&head, 2);
    ll.printList(head);
    return 0;
}
