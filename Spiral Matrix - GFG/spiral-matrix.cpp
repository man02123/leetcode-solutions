//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &mat, int n, int m, int k)
    {
        int l=0,r=m-1,t=0,d=n-1;
        
        while(t<=d && l<=r)
        {
            for(int j=l;j<=r;j++)
            {
                k--;
                if(k==0)
                return mat[t][j];
            }
            t++;
            
            for(int i=t;i<=d;i++)
            {
                k--;
                if(k==0)
                return mat[i][r];
            }
            r--;
            if(t<=d)
            {
                for(int j=r;j>=l;j--)
                {
                   k--;
                if(k==0)
                return mat[d][j]; 
                }
                d--;
            }
            if(l<=r)
            {
                for(int i=d;i>=t;i--)
                {
                   k--;
                if(k==0)
                return mat[i][l]; 
                }
                l++;
                
            }
        }
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends