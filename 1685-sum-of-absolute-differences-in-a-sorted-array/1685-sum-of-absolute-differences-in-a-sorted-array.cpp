class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> pre,suff;
        int sum = 0;
        pre.push_back(0);
        suff.push_back(0);
        for(auto it:nums){
            
             sum += it;
            pre.push_back(sum);
        }
        sum =0;
        for(int i =nums.size()-1 ; i>=0 ;i--){
            sum += nums[i];
            suff.push_back(sum);
        }
        reverse(begin(suff),end(suff));
        vector<int> ans;
        
        for(int i =0;i<nums.size();i++){
            int n = nums.size();
        int shuru = (i)*(nums[i]) - (pre[i]);
        int end =   suff[i+1]- ((n-(i+1))*nums[i]);
            
            ans.push_back(shuru + end);
        }
       return ans; 
    }
};