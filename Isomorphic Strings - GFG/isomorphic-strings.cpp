//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
        
        unordered_map<char,char> mp,mp2;
        if(s1.size()!=s2.size())
        return false;
        
        
        for(int i=0;i<s1.size();i++)
        {
            if((mp.find(s1[i])!=mp.end() && mp[s1[i]]!=s2[i]))
            return false;
            
            if(mp2.find(s2[i])!=mp.end() && mp2[s2[i]]!=s1[i])
            return false;
            
            else
            {
                mp[s1[i]]=s2[i];
                mp2[s2[i]]=s1[i];
            }
            
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends