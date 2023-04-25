//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        vector<int> temp(n+1);
        for(int i=2;i<=n;i++)
        temp[i] = i;
        
        for(int i=2;i*i<=n;i++)
        {
            if(temp[i]==i)
            {
                for(int j=i*i ;j<=n;j+=i)
                {
                    temp[j] = i;
                }
            }
        }
        vector<int> res;
        for(int i=2;i<=n;i++)
        {
            if(temp[i]==i && n>0 && n>=i && n%i==0)
            {
               while(n>0 && n>=i && n%i==0)
               {
                   n=n/i;
               res.push_back(i);
               }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends