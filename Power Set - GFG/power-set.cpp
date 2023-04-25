//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    
		    int n = s.size();
		    for( int  i=0 ;i<pow(2,n);i++)
		    {
		        string temp;
		        for(int j=0;j<=n-1;j++)
		        {
		            if((i>>j)&1 ==1)
		            {
		                //cout<<s[j];
		                temp.push_back(s[j]);
		            }
		        }
		        if(temp.size()!=0)
		        res.push_back(temp);
		    }
		    sort(res.begin(),res.end());
		    return res;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends