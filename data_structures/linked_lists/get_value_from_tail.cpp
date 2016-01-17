/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int
GetNode(Node *head, int positionFromTail)
{
    Node* p1 = head, *p2 = head;

    for (int i = 0; i < positionFromTail && p2->next; ++i)
        p2 = p2->next;

    while (p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1->data;
}

