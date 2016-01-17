/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node*
RemoveDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    while (curr) {
        Node *adv = curr->next;
        while (adv && adv->data == curr->data) {
            Node *temp = adv;
            curr->next = adv->next;
            adv = curr->next;
        }
        curr = curr->next;
    }

    return head;
}

