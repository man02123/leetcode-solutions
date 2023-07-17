class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0;i < (1<<n) ;i++)
           solve(res,i , nums);

        return res;
        
    }
    void solve(vector<vector<int>>&ans , int mask , vector<int> &nums)
    { 
       int j = 0;
       vector<int> t;
            while(mask > 0)
            {
                if((mask&1) == 1)
                {
                 t.push_back(nums[j]);
                }
                j++;
               mask= mask>>1;
            }
            
            ans.push_back(t);
        return;
    }
    
};


