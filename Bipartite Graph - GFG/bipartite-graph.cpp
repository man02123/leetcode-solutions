//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:bool ans;
	bool isBipartite(int V, vector<int>adj[]){
	    ans = true;
	    
	    
	    vector<int> vis(V),col(V,0);
	    
	    
	    for(int i = 0 ;i<V;i++){
	        
	        if(!vis[i]){
	            bfs(i,vis,col,adj);
	        }
	    }
	    return ans;
	    
	}
	void bfs(int node  , vector<int> &vis , vector<int>&col , vector<int>adj[]){
	    
	   queue<pair<int,int>> q;
	   q.push({node,1});
	   
	   while(q.size() >0){
	       int n = q.front().first;
	       int clr =q.front().second;
	       q.pop();
	       
	       for(auto it:adj[n])
	       {
	           if(vis[it] && col[it] == clr)
	           {
	               ans = false;
	               return;
	           }
	           else if(!vis[it])
	           {
	               q.push({it,-1*clr});
	               col[it] = -1*clr;
	               vis[it] = 1;
	           }
	              
	       }
	   }
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends