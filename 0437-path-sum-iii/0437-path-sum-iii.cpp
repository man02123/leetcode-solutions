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
public:int count;
    int t;
    int pathSum(TreeNode* root, int tgt) {
        count=0;
        t=tgt;
        forloop(root);
        return count;
    }
    void forloop(TreeNode* root)
    {
        if(root==NULL)return;
        
         if(root!=nullptr)
        {  
            if(root->val==t)
            count++;
            help(root->left,root->val);
            help(root->right,root->val);
        }
        
        forloop(root->left);
        forloop(root->right);
    }
    
    
    
    void help(TreeNode* root,long long psum)
    {
        if(root==NULL)return ;
        
        psum=psum+root->val;
        if(psum==t)count++;
        
        help(root->left,psum);
        help(root->right,psum);   
        
    }
};