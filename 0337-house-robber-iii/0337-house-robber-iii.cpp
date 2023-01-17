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
public://unordered_map<TreeNode*,int> mp;
//     int rob(TreeNode* root) {
//         bool take=true;
//         int y=help(root,take);
        
//         return y;
        
//     }
//     int help(TreeNode* root,bool pstate)
//     {
//         if(root==NULL)return 0;
//         if(mp.find(root)!=mp.end())return mp[root];
        
//         if(pstate==true)
//         {
//             int t=root->val+help(root->left,false)+help(root->right,false);
//             int nt=help(root->left,true)+help(root->right,true);
//             return mp[root]=max(t,nt);
//         }
//            return mp[root]=help(root->left,true)+help(root->right,true);
        
//     }
    unordered_map<TreeNode *,int> map;
    int rob(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(map.count(root))
            return map[root];
        int total=0;
        if(root->left)
            total+= rob(root->left->left)+rob(root->left->right);
        if(root->right)
            total+=rob(root->right->left)+rob(root->right->right);
        
        return map[root]=max(root->val+total,rob(root->left)+rob(root->right));
        
    }
};