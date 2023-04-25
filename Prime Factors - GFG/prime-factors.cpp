//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    vector<int> res;
	   // if(n==1)
	   // {
	   //     return {1};
	   // }
	    for(int i=2;i<=n;i++)
	    {
	        if(n>=i && n%i==0)
	        {
	            while(n>0 && n>=i && n%i==0)
	             n=n/i;
	          
	          res.push_back(i);
	          //i--;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends