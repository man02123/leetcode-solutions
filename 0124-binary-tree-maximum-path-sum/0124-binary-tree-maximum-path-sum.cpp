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
        
          int x= help(root,0);
        return maxi;
    }
    int help(TreeNode* root,int m)
    {
        if(root==NULL)return 0;
        
        int l=max(help(root->left,0),0);
        int r=max(help(root->right,0),0);
        
        int psum=l+root->val+r;
        
         maxi=max(maxi,psum);
    
        
        return root->val+(max(l,r));
       
        
    }
};