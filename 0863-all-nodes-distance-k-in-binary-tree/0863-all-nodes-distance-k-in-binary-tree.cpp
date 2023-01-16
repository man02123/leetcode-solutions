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
    unordered_map<TreeNode* ,TreeNode*> parent;
    vector<int> res;
    queue<TreeNode*> qtemp;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findparent(root);
        atdistk(target,k);
        while(qtemp.size()>0)
        {
            res.push_back(qtemp.front()->val);
            qtemp.pop();
        }
        
        return res;
    }
    void findparent(TreeNode* root)
    { 
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            TreeNode* r=q.front();
            q.pop();
            if(r->left!=NULL)
            {
                q.push(r->left);
                parent[r->left]=r;
            }
            if(r->right!=NULL)
            {
                q.push(r->right);
                parent[r->right]=r;
            } 
        }   
    }
    void atdistk(TreeNode* target,int dist)
    {
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        qtemp.push(target);
        
        while(qtemp.size()>0 && dist>0)
        {
            int lvl=qtemp.size();
            while(lvl>0)
            {
             TreeNode* temp=qtemp.front();
                qtemp.pop();
                lvl--;
                visited[temp]=true;
                
                if(temp->left!=NULL && visited[temp->left]!=true)
                {
                    qtemp.push(temp->left);
                }
                if(temp->right!=NULL && visited[temp->right]!=true)
                {
                    qtemp.push(temp->right);
                }
                if(parent[temp]!=NULL && visited[parent[temp]]!=true)
                {
                    qtemp.push(parent[temp]);
                }
            }
            dist--;
        }
        
    }
 
};