//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int i=s.size() ;
        int j=i;
        string res;
        while(i>=0 && j>=0)
        {
            while(j>=0 && s[j]!='.')
            j--;
            
            res+=s.substr(j+1,i-j);
            res.push_back('.');
            i=j-1;
            j=i-1;
        }
        for(int k=0;k<=i;k++)
          res.push_back(s[k]);
          if(res.back()=='.')
          res.pop_back();
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends