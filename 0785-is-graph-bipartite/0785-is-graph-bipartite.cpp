class Solution {
public:bool ans;
    bool isBipartite(vector<vector<int>>& adj) {
    ans = true;
	    
	    int V = adj.size();
	    vector<int> vis(V),col(V,0);
	    
	    
	    for(int i = 0 ;i<V;i++){
	        
	        if(!vis[i]){
	            bfs(i,vis,col,adj);
	        }
	    }
	    return ans;
	    
	}
	void bfs(int node  , vector<int> &vis , vector<int>&col , vector<vector<int>>&adj){
	    
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
