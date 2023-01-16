class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
       
        int n=nums.size();
        unordered_map<int,int> mp;
        long long cnt=0;
        long long ans=0;
        int j=0;
        
      for(int i=0;i<nums.size();i++)
      {
           mp[nums[i]]++;
          
          if(mp[nums[i]]>1)
             cnt+=mp[nums[i]]-1;
          
          while(cnt>=k)
          {
              ans+=n-i;
              if(mp[nums[j]]>1)
              cnt=cnt-(mp[nums[j]]-1);
              mp[nums[j]]--;
              j++;
          }
    
      }
       
        
         return ans;
        
    }
};