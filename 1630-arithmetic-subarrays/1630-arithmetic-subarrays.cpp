class Solution {
public: 
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        for(int i =0;i<l.size();i++){
            vector<int> tmp ={nums.begin()+l[i],nums.begin()+r[i]+1}; 
            ans.push_back(check(tmp));
        }
        return ans;
    }
    bool check(vector<int>& nums ){
        sort(nums.begin(), nums.end());
        
       
        int diff = nums[1]-nums[0];
        
        for(int i =1;i<nums.size();i++){
             if(diff != (nums[i]-nums[i-1]))return false;
        }

        return true;
    }
};