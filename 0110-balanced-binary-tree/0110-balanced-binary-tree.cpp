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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        balanced(root, ans);
        return ans;
    }
    
    int balanced(TreeNode *root, bool &ans){
        if(!root)
            return 0;
        if(!ans)
            return 0;
        
        int maxLeft = balanced(root->left , ans);
        int maxRight = balanced(root->right , ans);
        
        if(abs(maxLeft - maxRight) > 1)
            ans = false;
        return 1+max(maxLeft,maxRight);
        
    }
};