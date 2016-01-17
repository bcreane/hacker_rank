/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int
HasCycle(Node* head)
{
    if (head == NULL || head->next == NULL)
        return 0;

    Node *slow = head, *fast = head->next;
    while (slow && fast && slow != fast) {
        slow = slow->next;
        if (fast) {
            fast = fast->next;
        }
        if (fast && fast == slow)
            return 1;
        if (fast) {
            fast = fast->next;
        }
        if (fast && fast == slow)
            return 1;
    }

    return slow == fast ? 1 : 0;
}

