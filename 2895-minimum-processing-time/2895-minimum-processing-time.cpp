class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        vector<int> ntask;
        
        sort(t.begin() , t.end());
        sort(p.begin(),p.end());
        
        for(int i =3;i<t.size();i+=4){
            ntask.push_back(t[i]);   
        }
        reverse(ntask.begin(),ntask.end());
        int ans = 0;
        
        for(int i =0;i<p.size();i++){
            ans = max(ans,p[i]+ntask[i]);
            
        }
        
        return ans;
        
    }
};