class Solution {
public:
    long long minimumCost(string sr, string tar, vector<char>& o, vector<char>& c, vector<int>& cost) {
        
        vector<vector<long long >> dist(26,vector<long long>(26,LONG_MAX));
        for(int i =0;i<26;i++){
            dist[i][i] = 0;
        }
        

        
        for(int i =0;i<o.size();i++){
            dist[o[i]-'a'][c[i]-'a'] = min(dist[o[i]-'a'][c[i]-'a'],(long long)cost[i]);
        }
        
        for(int k =0;k<26;k++){
            for(int i =0;i<26;i++){
                
                for(int j =0;j<26;j++){
                       if ((dist[k][j] != LONG_MAX
                        && dist[i][k] != LONG_MAX)  && dist[i][j] > (dist[i][k] + dist[k][j]))
                    dist[i][j] = dist[i][k] + dist[k][j];
                   }
                }
            }
        
       long long ans = 0;
        
        for(int i =0;i<sr.size();i++){
            if(dist[sr[i]-'a'][tar[i]-'a'] >= INT_MAX)
                return -1;
            ans += dist[sr[i]-'a'][tar[i]-'a'];
        }
        if(ans == INT_MAX)return -1;
        
        return ans;
    }
//    long long fun(int src,int dest,vector<char>& o,vector<char>& c,vector<int>& cost){
       
       
//    }
};