/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
    Node* a = headA, *b = headB;
    while (a && b && a->data == b->data) {
        a = a->next;
        b = b->next;
    }
    if ((a && !b) || (b && !a))
        return false;
    else if ((a && b) && a->data != b->data)
        return false;
    return true;
}

