//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int k, vector<int> &nums) {
       
        map<int,int> mp;
           for(auto it:nums)
               mp[it]++;
        
           while(!mp.empty())
           {
               int cnt=0;
               vector<int> temp;
               for(auto it:mp)
               {
                   temp.push_back(it.first);
                   mp[it.first]--;
                   
                   if(mp[it.first]==0)
                       mp.erase(it.first);
                   
                   cnt++;
                   if(cnt==k)
                       break;
               }
               if(temp.size()<k)
               {
                   //cout<<temp.size();
                   return false;
               }
               for(int i=0;i<temp.size();i++)
               {
                   //cout<<temp[i];
                  if(i!=0 && temp[i-1]+1 != temp[i])
                      return false;
               }
               // cout<<" ";
           }
        
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends