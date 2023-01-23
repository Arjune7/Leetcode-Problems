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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameter_calc(root,diameter);
        return diameter;
        
    }
    
    int diameter_calc(TreeNode *root , int &diameter){
        if(!root)
            return 0;
        int maxLeft = diameter_calc(root->left , diameter);
        int maxRight = diameter_calc(root->right , diameter);
        diameter = max(diameter, maxLeft+maxRight);
        
        return 1 + max(maxLeft , maxRight);
    }
};