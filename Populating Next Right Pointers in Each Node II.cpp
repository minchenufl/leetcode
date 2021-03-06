/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root || (!root->left && !root->right))
            return ;
        TreeLinkNode *next = NULL, *tmp = root->next;
        while(tmp){
            if (tmp->left){
                next = tmp->left;
                break;
            }
            if (tmp->right){
                next = tmp->right;
                break;
            }
            tmp = tmp->next;
        }
        
        if (root->left)
            root->left->next = root->right ? root->right : next;
        if (root->right)
            root->right->next = next;
            
        connect(root->right);
        connect(root->left);
    }
};