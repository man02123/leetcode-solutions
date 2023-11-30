#define ll long long
class dsu {
    vector<ll> rank , par,sz;

    public :
    dsu(ll n){
        rank.resize(n+1,0);
        for(int i = 0 ;i<n+1;i++)
        par.push_back(i);
        sz.resize(n+1,1);
    } 
    // find thr parent
    ll findUparent(ll node){
       
       if(node == par[node]){
        return node;
       }
       par[node] = findUparent(par[node]);
return par[node];
    }

    // performing thr union
    void unionByrank(ll u , ll v){
        
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
    void unionbySize(ll u , ll v){
        ll upar = findUparent(u);
        ll vpar  = findUparent(v);

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
    string smallestEquivalentString(string s1, string s2, string base) {
        
        dsu ds(26);
        
        for(int i = 0;i<s1.size();i++)
            ds.unionbySize(s1[i]-'a' , s2[i]-'a');
        
        string res;
        
        for(int i = 0;i<base.size();i++){
            int c = base[i]-'a';
            int x = ds.findUparent(c);
            int ans = min(c,x);
            
            for(int i =0;i<26;i++){
                if(ds.findUparent(i) == x){
                    ans = min(ans,i);
                }
            }
            
            res.push_back(ans+'a');
        }
        return res;
        
    }
};