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
public:int sum;
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        if(root==nullptr)return root->val;
    
        help(root,0);
        return sum;
    }
    void help(TreeNode* root,bool flag)
    {
        if(root==nullptr)return ;
        if(root->left==NULL && root->right==NULL && flag==1)
        {
            sum+=root->val;
        }
        help(root->left,1);
        help(root->right,0);
    }
};