/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void
left_tree(node *root)
{
    if (root == NULL)
        return;
    
    left_tree(root->left);
    std::cout << root->data << " ";
}

void
right_tree(node *root)
{
    if (root == NULL)
        return;
    
    std::cout << root->data << " ";
    right_tree(root->right);
}

void top_view(node * root)
{
    if (root == NULL)
        return;
    left_tree(root->left);
    std::cout << root->data << " ";
    right_tree(root->right);
}

