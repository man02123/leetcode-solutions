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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        TreeNode* ans = NULL;
        return solve(r1,r2);
    }
    TreeNode* solve(TreeNode* r1, TreeNode* r2){
        
        if(r1==NULL && r2==NULL)
            return r1;
        if(r1==NULL && r2)
            return r2;
        if(r1 && !r2)
            return r1;
        
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        
        if(r1&& r2)
           l = solve(r1->left,r2->left);
        
        if(r1 && r2)
            r = solve(r1->right,r2->right);
 
        
        if(r1 && r2)
            r1->val+=r2->val;
        r1->left = l;
        r1->right= r;
        
        
        return r1;
        
        
    }
};