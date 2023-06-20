class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(),-1);
        if(k==0)
            return nums;
        
        int j = 0;
        long long  sum = 0;
        while(j<nums.size() && j<2*k)
            sum+=nums[j++];
        
        int sz = 2*k+1;
        for(int i = k+1;i+k-1<nums.size();i++){
            
            sum+=nums[i+k-1];
            res[i-1]=sum/sz;
            sum-=nums[i-k-1];
            
            
            
        }
       return res;     
    }
};