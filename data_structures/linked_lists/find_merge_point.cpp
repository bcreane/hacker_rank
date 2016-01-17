/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

#include <unordered_map>

int FindMergeNode(Node *headA, Node *headB)
{
    std::unordered_map<Node*, bool> visited;
    Node *a = headA;
    while (a) {
        visited[a] = true;
        a = a->next;
    }
    
    Node *b = headB;
    while (b) {
        if (visited[b] == true)
            return b->data;
        b = b->next;
    }
    return 0;
}

