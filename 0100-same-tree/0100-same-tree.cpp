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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q!=NULL)
            return false;
        if(q==NULL && p!=nullptr)
            return false;
        vector<int> v1,v2;
        preorder(p,v1);
        preorder(q,v2);
        if(v1==v2)
            return true;
        return false;
    }
    public:
    void preorder(TreeNode* root, vector<int>& v)
    {
        if(root==NULL)
        {
            v.push_back(0);
             return;
        }
           
            v.push_back(root->val);
        
            preorder(root->left,v);
        
            preorder(root->right,v);
            
        
    }
};