//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int> > res;
        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                int l=j+1;
                int r=n-1;
                while(l<r)
                {
                    if(nums[i]+nums[j]+nums[l]+nums[r]==k)
                    {
                        st.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                    }
                    else if(nums[i]+nums[j]+nums[l]+nums[r]>k)
                    r--;
                    else
                    l++;
                }
            }
        }
        res={st.begin(),st.end()};
        return res;
        
        
        
        
        //return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends