//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        vector<int> curr={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        
        int ind=curr.size()-1;
        
        while(ind>=0 && n<curr[ind])
        {
            ind--;
        }
        //cout<<ind;
        vector<int> res;
        while(n>1)
        {
            if(n>=curr[ind])
            {
                n=n-curr[ind];
                res.push_back(curr[ind]);
            }
            else
            ind--;
        }
        if(n==1)
        res.push_back(1);
        
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends