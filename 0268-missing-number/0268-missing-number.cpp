class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ptr = 0;
        int n = nums.size();
        
        while(ptr<n){
            
            while(nums[ptr]<n && nums[ptr]!=ptr){
                swap(nums[ptr],nums[nums[ptr]]);
            }
            ptr++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
                return i;
        }
        return n;
    }
};