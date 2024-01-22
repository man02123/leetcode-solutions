class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        vector<int> v;
        for(auto it:mp)
        {
           if(it.second==2)
               v.push_back(it.first);

        }
        for(int i=1;i<=nums.size();i++)
        {
            if(mp[i]==0)
                v.push_back(i);
            continue;
        }
        return v;
        
    }
};