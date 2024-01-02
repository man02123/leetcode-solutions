class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)mp[it]++;
        int mxf = 0;
        for(auto it:mp)mxf = max(mxf,it.second);
        
        vector<vector<int>> ans(mxf);
        
        for(int i =0;i<mxf;i++){
            
            for(auto &it:mp){
                if(it.second > 0){
                    ans[i].push_back(it.first);
                    it.second--;
                }
            }
        }
        return ans;
        
    }
};