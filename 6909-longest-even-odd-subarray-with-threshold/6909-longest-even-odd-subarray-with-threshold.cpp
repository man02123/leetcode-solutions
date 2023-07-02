class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int t) {
     
    int ans = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]%2==0  && nums[i]<=t)
            {
                ans = max(ans,1);
                int j =i+1;
                bool even =true;
                while(j<nums.size() && nums[j]<=t)
                {
                    if(even && nums[j]%2 ==1)
                    {
                        even = false;
                        ans = max(ans,j-i+1);
                        j++;
                    }
                    else if(!even && nums[j]%2==0)
                    {
                        even = true;
                        ans = max(ans,j-i+1);
                        j++;
                    }
                    else
                        break;
                }
                
            }
            
            
        }
        return ans;
    }
};