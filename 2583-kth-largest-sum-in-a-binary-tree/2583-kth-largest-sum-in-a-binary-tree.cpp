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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            int l=q.size();
            long long lsum=0;
            for(int i=0;i<l;i++)
            {
                if(q.front()->left!=nullptr)
                    q.push(q.front()->left);
                if(q.front()->right!=nullptr)
                    q.push(q.front()->right);
                lsum+=q.front()->val;
                q.pop();
            }
            v.push_back(lsum);
            
        }
        if(v.size()<k)
            return -1;
        
        sort(v.begin(),v.end());
        
        while(k>1)
        {
            v.pop_back();
            k--;
        }
        
        return v.back();
        
    }
};