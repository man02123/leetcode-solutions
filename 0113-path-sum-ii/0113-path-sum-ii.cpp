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
public:vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root,targetSum,temp);
       return res; 
        
    }
    void helper(TreeNode* root,int tgt,vector<int> &v)
    {
        if(root==nullptr)
            return;
        if(root->left==NULL && root->right==NULL && (tgt-root->val)==0)
        {
            v.push_back(root->val);
            res.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        helper(root->left,(tgt-root->val),v);
        helper(root->right,(tgt-root->val),v);
        v.pop_back();
           
    }
};