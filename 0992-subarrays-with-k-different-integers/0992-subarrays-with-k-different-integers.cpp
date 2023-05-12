class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return at(nums,k)-at(nums,k-1);
    }
    
    
    int at(vector<int>& nums, int k)
    {
      unordered_map<int,int> mp;
        int cnt =0;
        int l =0;
        
        for(int r =0;r<nums.size();r++)
        {
            mp[nums[r]]++;
            
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
                
                
            cnt +=r-l+1;   
        }
        return cnt;
    }
};