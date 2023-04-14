//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        int res=0;
        int i=0;
        int fmax=0;
        vector<int> mp(26);
        
        for(int j=0;j<s.size();j++)
        {
           mp[s[j]-'A']++;
           fmax=max(fmax,mp[s[j]-'A']);
           if(j-i+1-fmax<=k)
           {
               res=max(j-i+1,res);
               continue;
           }
           mp[s[i++]-'A']--;
        }
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends