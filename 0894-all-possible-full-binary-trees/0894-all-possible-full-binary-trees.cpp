// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
    
//     vector<TreeNode*> allPossibleFBT(int n) {
//          TreeNode* root = new TreeNode(0);
//          vector<TreeNode*> ans;
//          TreeNode* = recur( root ,n ,ans);
//         return ans;
        
//     }
//     TreeNode* recur( TreeNode * root , int n,vector<TreeNode*> &ans){
//         if(n == 0)
//         {
//             return root;
//         }
//         if(n%2 == 0){
//             return NULL;
//         }
        
//         if(n == 1)
//         {
//            TreeNode *l = new TreeNode(0); 
//             root->left = l;
//             ans.push_back(root);
//             root->left = NULL;
             
//             root->right = l;
//             ans.push_back(root);
//             root->right = NULL;
//             return ans;
//         }
        
//         else{
           
//             TreeNode *l = new TreeNode(0);
//             TreeNode *r = new TreeNode(0);
//             root->left = l;
//             root->right = r;
            
//             ans.push_back(recur(root->left , n-2 ));
//             ans.push_back(recur(root->right , n-2));
            
//             root->left = NULL;
//             root->right = NULL;
//         }
//      return root;         
//     }
        
// };

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1)
        {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> temp;
        for(int i=2;i<n;i++)
        {
            vector<TreeNode*>l=allPossibleFBT(i-1);
            vector<TreeNode*>r=allPossibleFBT(n-i);
            for(int j=0;j<l.size();j++)
            {
                for(int k=0;k<r.size();k++)
                {
                    TreeNode*root=new TreeNode(0);
                    root->left=l[j];
                    root->right=r[k];
                    temp.push_back(root);
                }
            }
        }
        return temp;
    }
};