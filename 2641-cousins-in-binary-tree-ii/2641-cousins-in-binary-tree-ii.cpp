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
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> lvlsum;
        root->val = 0;
        q.push(root);
        
        
        
        while(!q.empty())
        {
           int k=q.size();
            int sum = 0;
            for(int i=0;i<k;i++)
            {
               TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }  
            }
            lvlsum.push_back(sum);   
        }
        reverse(lvlsum.begin(),lvlsum.end());
        lvlsum.pop_back();
         reverse(lvlsum.begin(),lvlsum.end());
        
        q.push(root);
        
        int lvl=-1;
         while(!q.empty())
        {
           int k=q.size();
             lvl++;
            int sum = 0;
            for(int i=0;i<k;i++)
            {
               TreeNode* node = q.front();
                q.pop();
                int currsum =0;
                if(node->left!=NULL)
                {
                    currsum+=node->left->val;
                }
                if(node->right!=NULL)
                {
                    currsum+=node->right->val;   
                }
                
                 if(node->left!=NULL)
                {
                    node->left->val = lvlsum[lvl]-currsum;
                    q.push(node->left);
                }
                 if(node->right!=NULL)
                {
                    node->right->val = lvlsum[lvl]-currsum;
                    q.push(node->right);
                }
                
            }
              
        }
        
       // for(auto it:lvlsum)
       //     cout<<it<<" ";
     
        
        return root;
    }
};