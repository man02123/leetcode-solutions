//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
          int res=0;
        int sum=0;
        unordered_map<int,int> mp;
        mp[sum]++;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            sum++;
            
            if(mp.find(sum-k)!=mp.end())
                res+=mp[sum-k];
            
                mp[sum]++;   
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends