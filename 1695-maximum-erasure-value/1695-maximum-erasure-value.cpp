class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res=0,sum=0;
        int j=0,winlen=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            sum+=nums[i];
            winlen=i-j+1;
            
            if(mp.size()==winlen)
                res=max(res,sum);
            else
            {
                while(j<nums.size() && winlen>mp.size())
                {     
                  mp[nums[j]]--;
                  sum-=nums[j];
                
                  if(mp[nums[j]]==0)mp.erase(nums[j]);
                  j++;
                    winlen=i-j+1;
                } 
            }

        }
        return res;
        
    }
};