//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
vector<int> res;
    vector<int> subsetSums(vector<int> arr, int N)
    {
        recur(arr,0,0);
        return res;
    }
    void recur(vector<int> &arr,int ind,int sum)
    {
        if(ind>=arr.size())
        {
            res.push_back(sum);
            return ;
        }
        recur(arr,ind+1,sum+arr[ind]);
        recur(arr,ind+1,sum);
        
        
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
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends