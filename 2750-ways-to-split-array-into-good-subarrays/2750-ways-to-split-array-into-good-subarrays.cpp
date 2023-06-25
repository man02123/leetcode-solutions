// class Solution {
// public:
//     int numberOfGoodSubarraySplits(vector<int>& nums) {
       
        
//         int i=0;
//         int n = nums.size();
        
//         while(i<n && nums[i]==0)
//             i++;
        
//         if(i==n)
//             return 0;
//         long long ans = 1;
        
//         long long cnt= 0;
//         for(i;i<n;i++)
//         {
//             if(nums[i]==0)
//             {
//                 cnt++;
                
//             }
//             else
//             {
//                 long long t=ans*cnt;
//                 t=t%1000000007;
//                 ans+=t;
//                 cnt=0;
//             }
                
//         }
//         return ans%1000000007;
//     }
// };
class Solution {
public:
    int  dp[100001][2];
     int MOD=1e9+7;
     long long getAns(vector<int > &nums, int i, int k) {
        if(i >= nums.size()) {
            return k == 1; //if one 1 is there 
        }
        
        if(dp[i][k] != -1)return dp[i][k];
        
		
        if(k == 1) {
            if(nums[i] ==0) { //then i have two choice eithe break it here or  not
				
                return  dp[i][k]= (getAns(nums, i + 1, 0) % MOD + getAns(nums, i + 1, k) % MOD) % MOD;
            }
            else { //now i have to break it because one 1's in subarray is already present 
			
                return dp[i][k]=  getAns(nums, i + 1, 1) % MOD;
            }
        }
        else {
			
            return dp[i][k]=  getAns(nums, i + 1, k + nums[i]) % MOD;
        }
        
        
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
       return getAns(nums,0,0);
    }
};