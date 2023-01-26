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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum = 0;
        
        while(q.empty() == false){
            sum = 0 ;
            int n = size(q);
            
            for(int i = 0; i < n ; i++)
            {
                auto top = q.front();
                q.pop();
                sum+=top->val;
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return sum;
    }
};