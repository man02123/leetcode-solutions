class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int> hash(w.size()+10);
        
        for(int i = 0;i<w.size();i++){
            
            if((w[i][0]=='a' || w[i][0]=='i' || w[i][0]=='o' || w[i][0]=='e'|| w[i][0]=='u')  &&(w[i].back()=='a' || w[i].back()=='i' || w[i].back()=='o' || w[i].back()=='e'|| w[i].back()=='u') )
                hash[i+1]++;
            
        }
        for(int i=1;i<hash.size();i++)
            hash[i]=hash[i-1]+hash[i];
        
        vector<int> res;
        
        for(int i=0;i<q.size();i++){
            res.push_back(hash[q[i][1]+1]-hash[q[i][0]]);
        }
        return res;
        
    }
};