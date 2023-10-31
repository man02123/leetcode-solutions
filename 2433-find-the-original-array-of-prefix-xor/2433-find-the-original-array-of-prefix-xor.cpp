class Solution {
public:
    vector<int> findArray(vector<int>& p) {
        vector<int>ans;
        
       int cnum = p[0];
        ans.push_back(cnum);
        int run = p[0];
        
        for(int i =1;i<p.size();i++){
            
            ans.push_back(run^p[i]);
            run^=ans.back();
            
        
        }
        return ans;
    }
};