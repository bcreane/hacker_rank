/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
*/

#include <stdlib.h>
#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};

Node*
new_node(Node* next, int data)
{
    Node* new_node = (Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

void print_list(Node* head)
{
    Node*n = head;
    while (n) {
        std::cout << n->data << ", ";
        n = n->next;
    }
    std::cout << std::endl;
}

Node* InsertNth(Node *head, int data, int position)
{
    if (position == 0 || head == NULL) {
        head = new_node(head, data);
    } else if (position == 1 || head->next == NULL) {
        head->next = new_node(head->next, data);
    } else {
        Node* n = head;
        for (int p = 0; p < position && n->next; p++)
            n = n->next;
        n->next = new_node(n->next, data);
    }
    return head;
}

int
main()
{
    Node *head = NULL;
    head = InsertNth(head, 3, 0);
    print_list(head);

    head = InsertNth(head, 5, 1);
    print_list(head);

    head = InsertNth(head, 4, 2);
    print_list(head);

    head = InsertNth(head, 2, 4);
    print_list(head);

    head = InsertNth(head, 10, 1);
    print_list(head);

    return 0;
}

