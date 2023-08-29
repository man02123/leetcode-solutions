class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        int flag = true;
        
        for(i  = n-2;i>=0;i--){
            if(nums[i+1]>nums[i])
            {
                flag = false;
             break;
            }
            
        }
        if(flag == true)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int ind = i;
        
        for(i=n-1;i>=0;i--)
        {
           if(nums[ind] < nums[i])
           {
               swap(nums[ind] , nums[i]);
               break;
           }
            
        }
        reverse(nums.begin()+ind+1 , nums.end());
        
    }
};