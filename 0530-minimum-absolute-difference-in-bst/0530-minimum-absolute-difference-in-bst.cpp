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
    int getMinimumDifference(TreeNode* root) {
        help(root);
        //sort(begin(res),end(res));
        int mn=INT_MAX;
        for(int i=1;i<res.size();i++)
        {
            mn=min(mn,res[i]-res[i-1]);
        }
        return mn;
    }
    void help(TreeNode* root)
    {
        if(root==nullptr)return ;
        help(root->left);
        res.push_back(root->val);
        
        help(root->right);
        
    }
};