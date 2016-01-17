/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * lca(node * root, int v1, int v2)
{
    if (root == NULL)
        return root;
    
    if (v1 > v2)
        std::swap(v1, v2);

    if (v1 <= root->data && v2 >= root->data)
        return root;

    if (root->data < v1) {
        return lca(root->right, v1, v2);
    } else if (root->data > v2) {
        return lca(root->left, v1, v2);
    }

    return root;
}


