
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <queue>

void LevelOrder(node * root)
{
    if (root == NULL)
        return;

    std::queue<node*> fifo;
    fifo.push(root);

    while (!fifo.empty()) {
        node * n = fifo.front();
        fifo.pop();
        
        std::cout << n->data << " ";
        if (n->left)
            fifo.push(n->left);
        if (n->right)
            fifo.push(n->right);
    }
}

