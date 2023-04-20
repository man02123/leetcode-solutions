class Solution {
public:int maxi;
    int maxPathSum(TreeNode* root) {
        maxi=root->val;
        int t= psum(root);
        return maxi;
    }
    int psum(TreeNode* root)
    {
        if(root==NULL)
            return -10001;
        
        int l= max(psum(root->left),0);
        int r=max(psum(root->right),0);
        
        // int res=max({l,r,root->val});
        
        maxi=max({maxi,l+r+root->val,l+root->val,r+root->val});
        
        return max({root->val,l+root->val,r+root->val});
        
    }
};