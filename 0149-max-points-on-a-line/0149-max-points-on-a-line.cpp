class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        
        int mx=0;
        if(p.size()==1)return 1;
        
        for(int i=0;i<p.size();i++)
        {
            unordered_map<double,int> mp;
            
            for(int j=i+1;j<p.size();j++)
            {
                if(p[j][0]-p[i][0]!=0)
                {
                    double s=double(p[j][1]-p[i][1])/double(p[j][0]-p[i][0]);
                     mp[s]++;
                    mx=max(mx,mp[s]);
                }
                else  
                {
                    mp[90]++;
                    mx=max(mx,mp[90]);
                }
               
            }
        }
        
        return mx+1;
    }
};