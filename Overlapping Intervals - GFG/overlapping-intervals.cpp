//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& v) {
         sort(v.begin(),v.end());
         vector<vector<int>> res;
         res.push_back(v[0]);
         for(int j=1;j<v.size();j++)
         {
             if(res.back().back()<v[j][0])
             res.push_back(v[j]);
             else if(res.back().back()>=v[j][0])
             res.back().back()=max(res.back().back(),v[j][1]);
         }
         return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends