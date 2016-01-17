/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s)
{
    node* curr_node = root;

    for (size_t s_ndx = 0; s_ndx < s.size(); ++s_ndx) {
        switch(s[s_ndx]) {
        case '0':
            curr_node = curr_node->left;
            break;
        case '1':
            curr_node = curr_node->right;
            break;
        default:
            std::cout << "Unexpected input\n";
            return;
        }
        if (curr_node->data != '\0') {
            std::cout << curr_node->data;
            curr_node = root;
        }
    }
}

