class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        auto it1=nums.begin()+n-k;
        auto it2=nums.begin()+n-k;
        
        reverse(nums.begin(),it1);
        reverse(it2,nums.end());
        reverse(nums.begin(),nums.end());
        
    }
};