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
public:TreeNode* prev ;
    int ans;
    int getMinimumDifference(TreeNode* root) {
        ans= INT_MAX;
        prev= NULL;
        help(root);
        return ans;
    }
       
    void help( TreeNode* root)
    {
        if(root->left)
        {
             help(root->left );
        }
            if(prev)
                ans = min(ans,abs(prev->val - root->val));
            
        
        prev= root;
        if(root->right){
            help(root->right);
        }
        // return ans;
    }
};