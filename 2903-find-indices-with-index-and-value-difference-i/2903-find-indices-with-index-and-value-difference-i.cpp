class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int in, int val) {
        
        for(int i =0 ;i<nums.size();i++){
          for(int j = 0;j<=i;j++){
              if(abs(i-j) >= in  && abs(nums[i]-nums[j]) >= val)
                  return {i,j};
          }
        }
        return {-1,-1};
    }
};