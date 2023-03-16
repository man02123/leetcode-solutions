class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int cnt=0;
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<k;j++)
            {
                for(int i=0;i<j;i++)
                {
                    if(nums[j]-nums[i]==diff && nums[k]-nums[j]==diff)
                        cnt++;
                }
            }
        }
        return cnt;
        
    }
};