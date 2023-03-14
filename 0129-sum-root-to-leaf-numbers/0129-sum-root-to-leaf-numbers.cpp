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
public:int res;
    int sumNumbers(TreeNode* root) {
        string s;
        help(root,s);
      return res;  
    }
    void help(TreeNode* root,string s)
    {
        if(root==NULL)return;
        
        if(root->left==NULL && root->right==NULL)
        {
            s.push_back(root->val+'0');
            res+=stoi(s);
            return;
        }
        
        s.push_back(root->val+'0');
        help(root->left,s);
        help(root->right,s);

    }
};