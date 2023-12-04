class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        vector<vector<int>> mp(26);
        
        for(int i =0;i<s.size();i++){
            mp[s[i]-'a'].push_back(i);
        }
        
        int ans = 0;
        
        for(int i =0;i<w.size();i++){
            string x = w[i];
           
            bool  t = true;
            for(int j =0,prev = -1;j<x.size()&& t;j++){
                auto &m = mp[x[j]-'a'];
                
                auto ind = upper_bound(m.begin(),m.end(),prev);
                if(ind == m.end())t = false;
                   else
                   {
                       prev = *ind;
                       //cout<<prev;
                   }
                //cout<<*ind<<" ";
            }
            if(t)ans++;
        }
        return ans;
    }
};


