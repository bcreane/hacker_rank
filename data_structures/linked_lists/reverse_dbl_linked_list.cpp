/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

Node* Reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* n = head;
    while (n->next) {
        std::swap(n->next, n->prev);
        n = n->prev;
    }
    std::swap(n->next, n->prev);
    
    return n;
}
