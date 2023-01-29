class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        if(k==1 || k==w.size())
            return 0;
        
        vector<int> v;
        for(int i=0;i+1<w.size();i++)
            v.push_back(w[i]+w[i+1]);
        
         sort(v.begin(),v.end());  
        long long res=0;
        for(int i=0;i<k-1;i++)
            res+=v[v.size()-1-i]-v[i];
        
        return res;
    }
};