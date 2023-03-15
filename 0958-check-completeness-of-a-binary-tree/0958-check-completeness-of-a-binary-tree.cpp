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
    bool isCompleteTree(TreeNode* root) {
    bool flag=true;
      queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
              TreeNode* x=q.front();
                q.pop();
                if(x==NULL)
                    flag=false;
               else {
                   
                if(flag==false && x!=NULL)
                    return false;
                else
                {
                    q.push(x->left);
                    q.push(x->right);
                }
               }
            }
        }
        return true;
        
    }
};