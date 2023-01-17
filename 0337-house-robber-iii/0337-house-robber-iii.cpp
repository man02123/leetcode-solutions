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
public:map<pair<TreeNode*,bool>,int> mp;
    int rob(TreeNode* root) {
        bool take=true;
        int y=help(root,take);
        
        return y;
        
    }
    int help(TreeNode* root,bool pstate)
    {
        if(root==NULL)return 0;
        if(mp.find({root,pstate})!=mp.end())return mp[{root,pstate}];
        
        if(pstate==true)
        {
            int t=root->val+help(root->left,false)+help(root->right,false);
            int nt=help(root->left,true)+help(root->right,true);
            return mp[{root,pstate}]=max(t,nt);
        }
           return mp[{root,pstate}]=help(root->left,true)+help(root->right,true);
        
    }
};