#define ll long long
class dsu {
    vector<ll> rank , par,sz;

    public :
    dsu(int n){
        rank.resize(n+1,0);
        for(int i = 0 ;i<n+1;i++)
        par.push_back(i);
        sz.resize(n+1,1);
    } 
    // find thr parent
    int findUparent(int node){
       
       if(node == par[node]){
        return node;
       }
       par[node] = findUparent(par[node]);
       return par[node];
    }

    // performing thr union
    void unionByrank(int u , int v){
        
        ll upar = findUparent(u);
        ll vpar = findUparent(v);

        if(vpar == upar)return;

       if( rank[upar] < rank[vpar]){
        par[upar] = vpar;
       }
       else if(rank[upar] > rank[vpar]){
        par[vpar] = upar;
       }
       else{
        par[vpar] = upar;
        rank[upar]++;
       }
    }
    // performing union by size
    void unionbySize(int u , int v){
        int upar = findUparent(u);
        int vpar  = findUparent(v);

        if(upar == vpar)return;

        if(sz[upar] > sz[vpar]){
            par[vpar] = upar;
            sz[upar] += sz[vpar];
        }
        else {
            par[upar] = vpar;
            sz[vpar] += sz[upar];
        } 
    }

};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
        
        dsu ds(s.size());
        
        for(int i = 0;i<p.size();i++){
            ds.unionbySize(p[i][0] , p[i][1]);
        }
        
        map<int, vector<int>> mp;
        
        for(int i = 0;i<s.size();i++){
           int par = ds.findUparent(i);
          
            mp[par].push_back(i);
            
        }
        // for(auto it:mp)
        //     mp[it.first].push_back(it.first);
        
        vector<char> ans(s.size());
        
        for(auto it:mp){
            auto x = it.second;
       
           string ch;
            for(auto it2:x){
                ch.push_back(s[it2]);
            }
            sort(x.begin(),x.end());
            
           sort(ch.begin(),ch.end());
            int k= 0;
            for(auto it2:x){
                ans[it2] = ch[k++];
            }
        }
        string t;
        for(auto it:ans)
            t.push_back(it);
        
       return t ;
    }
};