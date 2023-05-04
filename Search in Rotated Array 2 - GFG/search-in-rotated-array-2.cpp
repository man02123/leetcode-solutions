//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& nums, int key) {
        
        int l = 0,r =n-1;
        
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            
            if(nums[mid] == key)
            return true;
            
            while(nums[mid] == nums[l] && nums[mid] == nums[r] && l<r)
            {
                l++;
                r--;
            }
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=key && nums[mid]>=key)
                r = mid-1;
                else
                l = mid+1;
            }
            else
            {
                if(nums[mid]<key && nums[r]>=key)
                l = mid+1;
                else
                r = mid-1;
            }
            
            
        }
        return false;
    
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends