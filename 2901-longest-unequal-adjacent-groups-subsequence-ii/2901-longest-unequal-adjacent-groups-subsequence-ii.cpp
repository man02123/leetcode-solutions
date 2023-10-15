class Solution {
public:
    bool check(string &x , string &y){
        if(x.size() != y.size())return false;
        
        int total = 0;
        for(int i =0;i<x.size();i++){
            if(x[i] != y[i])total++;

        }
        if(total >1)return false;
        return true;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& w, vector<int>& g) {
        
        vector<int> res(n,-1);
        for(int i =0;i<n;i++)
            res[i] = i;
        
        vector<int> ans(n,1);
        
        vector<string> x;
        int mx = 0;
        for(int i = 0;i<g.size();i++){
            
            for(int j = 0;j<i;j++){
                if(g[i] != g[j]  && 1+ans[j] >= ans[i] && check(w[i] , w[j])){
                   
                    ans[i] = 1+ans[j];
                    res[i] = j;
                } 
                
            }
        }
        int lon = *max_element(begin(ans) , end(ans));
        
        int i = 0;
        for( i =0;i<n;i++){
            if(lon == ans[i])break;
        }
        while(res[i] != i){
            x.push_back(w[i]);
            i = res[i];
        }
        x.push_back(w[i]);
        
        reverse(begin(x) , end(x));
        
        return x;
        
        
    }
};




        
        
