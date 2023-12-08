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
    string tree2str(TreeNode* root) {
        string s;
        return help(s,root);
    }
    string help(string &s,TreeNode* root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            s+=to_string(root->val);
            return s;
        }
        
        s+=to_string(root->val);
        
        if(root->left!=NULL)
        {
            s.push_back('(');
            help(s,root->left);
            s.push_back(')');
        }
        if(root->left==nullptr && root->right!=NULL)
            s+="()";
        
         if(root->right!=NULL)
        {
            s.push_back('(');
            help(s,root->right);
             s.push_back(')');
        }
        
        
       return s; 
        
    }
};