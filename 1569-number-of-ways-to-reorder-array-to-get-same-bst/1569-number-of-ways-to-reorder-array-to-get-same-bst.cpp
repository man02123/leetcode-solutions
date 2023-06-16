class Solution {
public:vector<vector<long long>> ncr;
     long long MOD = 1e9 + 7;
    
    int numOfWays(vector<int>& nums) {
       int n = nums.size();
        //n=8;
        ncr.resize(n+1,vector<long long>(n+1,1));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
            }
        }
        
        return solve(nums) - 1;
    }
   

    unsigned long long solve(vector<int> &nums) {
        if (nums.size() <= 1) return 1;
        vector<int> l, r;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) r.push_back(nums[i]);
            else l.push_back(nums[i]);
        }
        int n = l.size(), m = r.size();
        return solve(l) * solve(r) % MOD * ncr[n + m][n] % MOD;
    }
};