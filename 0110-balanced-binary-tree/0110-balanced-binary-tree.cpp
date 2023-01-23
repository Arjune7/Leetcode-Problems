/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int balanced(TreeNode* root,bool &x)
{
    if(root==NULL)
        return 0;
    
    if(x==false)
        return 0;
    
    int l=balanced(root->left,x);
    int r=balanced(root->right,x);
    
    if(abs(l-r)>1)
        x=false;
    
    return 1+max(l,r);
}

bool isBalanced(TreeNode* root) {
    
    bool x=true;
    balanced(root,x);
    
    return x;
}
};