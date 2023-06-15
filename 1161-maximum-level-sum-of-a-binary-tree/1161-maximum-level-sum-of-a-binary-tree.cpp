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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxsum=root->val;
        int reslvl=0;
        
       int lvl=0;
        q.push(root);
        
       while(q.size()!=0)
       {
           int k=q.size();
           int lvlsum=0;
           while(k!=0)
           {
               if(q.front()->left!=nullptr)
                  q.push(q.front()->left);
                   
                   if(q.front()->right!=nullptr)
                    q.push(q.front()->right);
                   
               lvlsum=lvlsum+q.front()->val;
               
               q.pop();
               k--;
           }
           
           if(lvlsum>maxsum)
           {
               maxsum=lvlsum;
               reslvl=lvl;
           }
           
           lvl++;  
       }
        return reslvl+1;
        
    }
  
};