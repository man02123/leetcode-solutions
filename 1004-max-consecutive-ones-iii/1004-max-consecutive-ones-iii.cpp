class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        //unordered_map<int,int> mp;
        int st = 0;
        for(int end=0;end<nums.size();end++)
        {
            
            if(nums[end] == 0)
                k--;
            while(k<0)
            {
                if(nums[st]==0)
                    k++;
                st++;
            }
            ans = max(ans,end-st+1);
                
        }
        
        return ans;
        
    }
};