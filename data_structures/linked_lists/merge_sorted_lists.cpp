/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node*
new_node(Node* next, int data)
{
    Node* new_node = (Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

Node*
append(Node* head, int data)
{
    if (head == NULL) {
        head = new_node(NULL, data);
    } else if (head->next == NULL) {
        head->next = new_node(NULL, data);
    } else {
        Node *n = head;
        while (n->next)
            n = n->next;
        n->next = new_node(NULL, data);
    }
    return head;
}

Node*
MergeLists(Node *headA, Node* headB)
{
    Node *new_head = NULL;
    Node *a = headA, *b = headB;
    
    while (a && b) {
        if (a->data < b->data) {
            new_head = append(new_head, a->data);
            a = a->next;
        } else {
            new_head = append(new_head, b->data);
            b = b->next;
        }
    }

    while (a) {
        new_head = append(new_head, a->data);
        a = a->next;
    }

    while (b) {
        new_head = append(new_head, b->data);
        b = b->next;
    }

    return new_head;
}

