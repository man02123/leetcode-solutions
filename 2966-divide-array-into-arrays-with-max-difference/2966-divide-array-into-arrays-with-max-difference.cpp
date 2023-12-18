class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
       
        
        for(int i = 0;i<nums.size();i++){
            
           if(i+2< nums.size() && ((nums[i+2]-nums[i]) <= k)){
               //cout<<nums[i+2]-nums[i];
               ans.push_back({nums[i],nums[i+1],nums[i+2]});
               i+=2;
           }
        }
        if(ans.size() != nums.size()/3)
            return {};
        return ans;
    }
};