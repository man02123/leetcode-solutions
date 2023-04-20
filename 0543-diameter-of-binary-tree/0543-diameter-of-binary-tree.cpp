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
    int diameterOfBinaryTree(TreeNode* root  ) {
        maxi = 0;
        int temp = dia(root);
        return maxi;
    }
    int dia(TreeNode* root )
    {
        if(root == NULL)
            return 0 ;
        int lp=dia(root->left);
        int rp= dia(root->right);
        
        maxi=max(maxi,lp+rp);
        
        return max(1+lp,1+rp);
    }
};