class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        int digsum=0;
            for(auto it:nums)
            {
                string s=to_string(it);
                for(auto it:s)
                {
                    digsum+=it-'0';
                }
            }
        return abs(digsum-sum);
        
    }
};