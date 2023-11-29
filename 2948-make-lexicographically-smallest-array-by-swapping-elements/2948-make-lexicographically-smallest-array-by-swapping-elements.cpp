class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int lim) {
        vector<pair<int,int>> t;
        for(int i =0;i<nums.size();i++)t.push_back({nums[i],i});
        
        sort(begin(t),end(t));
        map<int, vector<pair<int,int>>> mp;
        
        int x = 0;
        mp[x].push_back(t[0]);
        for(int i =1;i<t.size();i++){
            
            auto [elem,ind] = t[i];
            
            if(elem -t[i-1].first > lim){
                x++;
            }
            mp[x].push_back(t[i]);
        }
        vector<int> ans(nums.size());
        
        for(auto it : mp){
            
            vector<int> elem , ind;
            auto vec = it.second;
            
            for(int it2 = 0 ;it2 <vec.size();it2++){
                elem.push_back(vec[it2].first);
                ind.push_back(vec[it2].second);
            }
            sort(elem.begin() , elem.end());
            sort(ind.begin() , ind.end());
            
            for(int i =0;i<ind.size();i++){
                ans[ind[i]] = elem[i];
            }
        }
        return ans;
    }
};