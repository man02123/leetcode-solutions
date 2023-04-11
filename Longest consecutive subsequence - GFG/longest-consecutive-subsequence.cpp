//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      set<int> s;
      for(int i=0;i<n;i++)
      s.insert(a[i]);
      
      vector<int> temp;
      for(auto it:s)
      temp.push_back(it);
      
      int res=1,curr=1;
      for(int i=1;i<temp.size();i++)
      {
          if(temp[i]==temp[i-1]+1)
          {
              curr+=1;
              res=max(res,curr);
          }
          else
          curr=1;
      }
      return res;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends