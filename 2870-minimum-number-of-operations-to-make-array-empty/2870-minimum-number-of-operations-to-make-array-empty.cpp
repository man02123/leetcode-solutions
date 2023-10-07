class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        int ans = 0;
        
        for(auto it:mp){
            
             int t = it.second;
            if(t == 1)
                return -1;
           
              
             if(t%3 == 0)ans += t/3;
             else {
                 ans+= (t/3)+1;

                 
             }
            
          }
            
        return ans;
        
    }
};