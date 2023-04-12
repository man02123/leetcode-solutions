//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string s[], int n)
    {
        string res=s[0];
        for(int i=1;i<n;i++)
        {
            int k=0;
            int j;
            for( j=0;j<min(res.size(),s[i].size());j++)
            {
                if(s[i][j]==res[k])
                k++;
                else
                break;
            }
            string temp=s[i].substr(0,k);
            res=temp;
        }
        if(res.size()==0)
        return "-1";
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends