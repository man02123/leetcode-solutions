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
public:unordered_map<TreeNode*,TreeNode*> parent;          
    int amountOfTime(TreeNode* root, int start) {
         TreeNode* st=findroot(root,start);
         markparent(root);
         return time(st);         
    }
           void markparent(TreeNode* root)
              {
                  queue<TreeNode*> q;
                  q.push(root);
                  while(q.size()>0)
                  {
                      TreeNode* r=q.front();
                      q.pop();
                      if(r->left!=NULL)
                      {
                          parent[r->left]=r;
                          q.push(r->left);
                      }
                      if(r->right!=NULL)
                      {
                          parent[r->right]=r;
                          q.push(r->right);
                      }
                  }
                  
              }
             TreeNode* findroot( TreeNode* root,int start) 
              {
                  if(root==NULL)return NULL;
                  
                  if(root->val==start)return root;
                  
                   TreeNode* left=findroot(root->left,start);
                   TreeNode* right=findroot(root->right,start);
                  
                  if(left!=NULL)return left;
                  return right;
                  
              }
              int time(TreeNode* st)
              {
                  queue<TreeNode*> q;
                  unordered_map<TreeNode*,bool> visited;
                  q.push(st);
                  int t=0;
                  while(q.size()>0)
                  {
                      int lvl=q.size();
                      while(lvl>0)
                      {
                          TreeNode* f=q.front();
                          q.pop();
                          visited[f]=true;
                          
                          if(f->left!=NULL && visited[f->left]!=true)
                          {
                              q.push(f->left);
                          }
                          if(f->right!=NULL && visited[f->right]!=true)
                          {
                              q.push(f->right);
                          }
                          if(parent[f]!=NULL && visited[parent[f]]!=true)
                          {
                              q.push(parent[f]);
                          }
                          lvl--;
                          
                      }
                      
                      t++;
                  }
                  
                return t-1;  
              }
    
                        
              
};