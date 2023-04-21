/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    map<TreeNode* ,TreeNode* >mp;
    
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
     
           mark(root);
       // TreeNode *mynode = fnode(root,tar);
        // cout<<mp[mynode]->data;
        //x=mynode;
        dist(tar,k);
        sort(res.begin(),res.end());
        return res;
    }
    void mark(TreeNode* root)
    {
        if(root==NULL)
        return ;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0)
        {
            TreeNode * temp = q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
    }
//     TreeNode* fnode(TreeNode* root,int tar)
//     {
//         if(root==NULL)
//         return NULL;
        
//         if(root->data  == tar)
//         return root;
        
//         Node* l = fnode(root->left,tar);
//         Node* r = fnode(root->right,tar);
        
//         if(l!=NULL)
//         return l;
        
//         return r;
//     }
    
void dist(TreeNode* mynode,int k)
{
    unordered_map<TreeNode*,bool> vis;
    queue<pair<TreeNode *,int>> q;
    q.push({mynode,0});
    vis[mynode]=true;
    
    int l=k;
    while(q.size()>0)
    {
        
            TreeNode* temp = q.front().first;
            int d=q.front().second;
            if(d==l)
            res.push_back(temp->val);
            q.pop();
            vis[temp]= true;
            
            if(mp.find(temp)!=mp.end() && vis[mp[temp]]==false)
            {
                q.push({mp[temp],d+1});
            }
            if(temp->left!=NULL && vis[temp->left]==false)
            {
              q.push({temp->left,d+1});  
            }
            if(temp->right!=NULL && vis[temp->right]==false)
            {
              q.push({temp->right,d+1});  
            }
            
        k--;
    }
   
}
};
        
 