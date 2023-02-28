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
public:unordered_map<string,int> mp;
        vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string temp;
        help(root,temp);
        return ans;
        
    }
    string help(TreeNode* root,string s)
    {
        if(root==NULL)
        {
            s.push_back('x');
            return s;
        }
       
         
        string l=help(root->left,s);
        
        if(l=="x")
        l.back()='L';
        
        string rt=l+to_string(root->val);
        string r=help(root->right,s) ;
        rt+=r;
        
         mp[rt]++;
        
        if(mp[rt]==2)
        ans.push_back(root);
           
        
        
       return rt; 
        
    }
};
// class Solution {
// public:vector<TreeNode*> res;
//     unordered_map<string,int> mp;
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         string temp;
//         string x=  help(root,temp);
//         return res;
//     }

//     string help(TreeNode* root,string t)
//     {
//         if(root==nullptr)
//         {
//             t.push_back('x');
//             return t;
//         }
        
//         string l=help(root->left,t);
//         if(l=="x")
//             l="L";

//         string rt=l+to_string(root->val);
//         string r=help(root->right,t) ;
//         rt+=r;
        
//         if(mp.find(rt)==mp.end())
//            mp[rt]++;
//         else
//         {
//             if(mp[rt]!=-1)
//             {
//                res.push_back(root);
//               mp[rt]=-1;  
//             }
           
//         }
//         return rt;
       
//     }
// };