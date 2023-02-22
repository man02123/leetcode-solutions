class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums.size()==3)
            return nums[n-1]*nums[n-2]*nums[n-3];
        
        if(nums[0]>=0)
            return nums[n-1]*nums[n-2]*nums[n-3];
        
        int allneg=nums[0]*nums[1]*nums[2];
        int neg=nums[0]*nums[1];
        int pos=nums[n-1]*nums[n-2]*nums[n-3];
        int negpos=neg*nums.back();
        
        return max({allneg,pos,negpos});
    }
};