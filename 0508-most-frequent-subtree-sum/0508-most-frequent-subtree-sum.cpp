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
public:vector<int> res;
    int maxf;
    unordered_map<int,int> mp;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxf=0;
     int x= solve(root);
     
        bool flag=true;
        for(auto it:mp)
            if(it.second==maxf)
                res.push_back(it.first);
        
        return res;
    }
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
       int f=solve(root->left) + solve(root->right)+root->val;
        mp[f]++;
        maxf=max(maxf,mp[f]);
        return f;   
    }
    
    
};