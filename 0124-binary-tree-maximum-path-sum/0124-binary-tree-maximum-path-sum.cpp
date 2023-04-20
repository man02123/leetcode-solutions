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
public:int maxi;
    int maxPathSum(TreeNode* root) {
        maxi=root->val;
       psum(root,0);
        return maxi;
    }
    int psum(TreeNode* root,int sum)
    {
        if(root==NULL)
            return 0;
        
        int l= max(psum(root->left,sum),0);
        int r=max(psum(root->right,sum),0);
        
        int res=l+r+root->val;
        
        maxi=max(maxi,res);
        
        return max(l,r)+root->val;
        
    }
};