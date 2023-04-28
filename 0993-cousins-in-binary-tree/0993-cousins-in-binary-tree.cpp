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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> qu;
        qu.push(root);
        int lvl =0;
        int px=-1,py=-1;
        while(qu.size()>0)
        {
            
            int sz=qu.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* q = qu.front();
                qu.pop();
                if(q->left!=NULL && q->right!=NULL)
                {
                    if(q->left->val == x && q->right->val == y)
                        return false;
                    if(q->left->val == y && q->right->val == x)
                        return false;
                }
                
                
                if(q->left!=NULL && q->left->val == x)
                    px=1+lvl;
                 if(q->left!=NULL && q->left->val == y)
                    py=1+lvl;
                
                 if(q->right!=NULL && q->right->val == x)
                    px=1+lvl;
                 if(q->right!=NULL && q->right->val == y)
                    py=1+lvl;
                
                if(q->left)
                qu.push(q->left);
                if(q->right)
                qu.push(q->right);
                
            }
            if(px!=-1 && py!=-1)
            {
                if(px == py)
                    return true;
            }
            lvl++;
            
        }
        return false;
        
    }
};