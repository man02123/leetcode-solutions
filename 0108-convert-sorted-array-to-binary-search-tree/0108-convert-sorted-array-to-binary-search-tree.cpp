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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return create(nums,0,nums.size()); 
    }
    TreeNode* create(vector<int>& nums,int l,int r)
    {
        int mid=(l+r)/2;
        if(l>r || mid<0 || mid>nums.size()-1)
        return nullptr;
        
        TreeNode* root=new TreeNode(nums[mid]);
        
            //root->val=(nums[mid]);
        
        root->left=create(nums,l,mid-1);
        root->right=create(nums,mid+1,r);
        return root;
        
    }
};