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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>res1,res2;
        helper(root1,res1);
        helper(root2,res2);
        if(res1==res2)return true;
        return false;
        
    }
    void helper(TreeNode* root,vector<int>&res)
    {
        if(root==nullptr)return;
        if(root->left==nullptr  && root->right==NULL)
        {
            res.push_back(root->val);
        }
        helper(root->left,res);
        helper(root->right,res);

    }
    
};