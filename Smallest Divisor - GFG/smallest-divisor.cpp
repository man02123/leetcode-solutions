//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestDivisor(vector<int>& nums, int k) {
       
       int l=1;
       int r=-1;
       for(auto it:nums)
        r=max(r,it);
       //int r=max_element(nums.begin(),nums.end());
       int res=r;
       while(l<=r)
       {
           int mid=l+(r-l)/2;
           
           if(check(nums,mid)<=k)
            {
                res=min(res,mid);
                r=mid-1;
            }
            else
            l=mid+1;
       }
       return res;
    }
    int check(vector<int>& nums,int div)
    {
        int tsum=0;
        for(auto it:nums)
        {
            int x=(it/div);
            tsum+=x;
            if(it%div!=0)
            tsum+=1;
        }
        return tsum;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends