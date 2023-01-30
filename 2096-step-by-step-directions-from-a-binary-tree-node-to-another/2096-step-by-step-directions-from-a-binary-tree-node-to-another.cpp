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
    string lts;
    string ltd;
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode * lca=flca(root,s,d);
        string temp;
        tra1(lca,s,temp);
        tra2(lca,d,temp);
        cout<<lca->val;
        for(auto i=0;i<lts.size();i++)
            lts[i]='U';
        
        
        return lts+ltd;
    }
   TreeNode *flca(TreeNode* root, int s, int d) 
   {
       if(root==NULL)
           return NULL;
 
       if(s==root->val || d==root->val)
           return root;
       
       TreeNode * l=flca(root->left,s,d);
       TreeNode * r=flca(root->right,s,d);
       
       if(l!=NULL && r!=NULL)
           return root;
       
       return (l!=NULL)?l:r;
       
   }
    void tra1(TreeNode* root, int s,string &temp)
    {
        if(root==NULL)
            return ;
        
        if(root->val==s)
        {
            lts=temp;
            return ;
        }
        temp.push_back('L');
        tra1(root->left,s,temp);
        temp.pop_back();
        temp.push_back('R');
        tra1(root->right,s,temp);
        temp.pop_back();
    
    }
    void tra2(TreeNode* root, int d,string &temp)
    {
        if(root==NULL)
            return ;
        
        if(root->val==d)
        {
            ltd=temp;
            return ;
        }
        temp.push_back('L');
        tra2(root->left,d,temp);
        temp.pop_back();
        temp.push_back('R');
        tra2(root->right,d,temp);
        temp.pop_back();
    }
};