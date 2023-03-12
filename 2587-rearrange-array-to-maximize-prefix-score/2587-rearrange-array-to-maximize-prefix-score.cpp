class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int cnt=0;
        int i=1;
      vector<long long> arr;
        long long psum=nums[0];
       arr.push_back(psum);
        if(psum>0)
            cnt++;
        
        for(;i<nums.size();i++)
        {
            psum+=nums[i];
            if(psum>0)
                cnt++;
            
           arr.push_back(psum);
        }
       
        return cnt;
        
    }
};