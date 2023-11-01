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
public:vector<int> ans;
    int currf;
    int maxf;
    int tval ;
    vector<int> findMode(TreeNode* root) {
        maxf = 1;
        currf =0;
        tval = INT_MAX;
       
        solve(root );
        return ans;
    }
    
    
    void solve(TreeNode* root  ){
         if(root == NULL)return;
        
         solve(root->left);
        
        if(root->val == tval){
            currf++;
            if(currf == maxf){
                
                ans.push_back(root->val);
                
            }else if(currf > maxf){
                maxf = currf;
                ans.clear();
                ans.push_back(tval);
            }
            
        }   
        else{
            currf= 1;
            if(currf == maxf){ans.push_back(root->val);}
        }
        tval = root->val;   
        solve(root->right);
        
    }
};