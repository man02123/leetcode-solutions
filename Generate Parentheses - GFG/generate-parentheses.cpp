//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
     vector<string> res;
    int x;
    vector<string> AllParenthesis(int n) 
    {
        x=n;
        recur(2*n,"",0,0);
        return res;
    }
    void recur(int n,string temp,int open,int close)
    {
        if(n==0 && open==x && close==x)
        {
            res.push_back(temp);
            return;
        }
        //cout<<n;
        if(open>=close && open<=x)
        {
            temp.push_back('(');
                recur(n-1,temp,open+1,close);
            temp.pop_back();
            
            temp.push_back(')');
                recur(n-1,temp,open,close+1);
            
        } 
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends