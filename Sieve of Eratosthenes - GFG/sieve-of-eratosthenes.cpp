//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int> temp(n+4);
        for(int i=2;i<=n;i++)
        {
            temp[i]=i;
        }
        for(int i=4;i<=n;i+=2)
        {
            temp[i] = 2;
        }
        for(int i=3;i*i<=n;i++)
        {
            for(int j = i*i;j<=n;j+=i)
            {
                if(temp[j]=j)
                temp[j] = i;
            }
        }
        vector<int> res;
        for(int i=2;i<=n;i++)
        {
            if(temp[i]==i)
            res.push_back(i);
        }
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends