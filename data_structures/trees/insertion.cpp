/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node*
new_node(int data)
{
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *
insert(node * root, int value)
{
    if (root == NULL) {
        root = new_node(value);
    } else {
        if (value > root->data) {
            if (root->right == NULL)
                root->right = new_node(value);
            else
                root->right = insert(root->right, value);
        } else {
            if (root->left == NULL)
                root->left = new_node(value);
            else
                root->left = insert(root->left, value);
        }
    }
    
    return root;
}

