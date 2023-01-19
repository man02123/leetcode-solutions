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
public:unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++)
            mp[in[i]]=i;
        
       return build(pre,0,pre.size()-1,in,0,in.size()-1); 
    }
   TreeNode* build(vector<int>& pre,int pstart,int pend,vector<int>& in,int istart,int iend )
   {
       if(istart>iend || pstart>pend)
           return NULL;
       
       TreeNode* root=new TreeNode(pre[pstart]);
       int inroot=mp[pre[pstart]];
       int numleft=inroot-istart;
    
       root->left=build(pre,pstart+1,pstart+numleft,in,istart,inroot-1);
       
           root->right=build(pre,pstart+numleft+1,pend,in,inroot+1,iend);
       
       return root;
       
   }
};