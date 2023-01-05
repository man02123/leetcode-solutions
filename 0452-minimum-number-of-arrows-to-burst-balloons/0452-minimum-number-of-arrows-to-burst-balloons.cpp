class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        // vector<vector<int>> res;
        // res.push_back(p[0])
        int minend=INT_MAX;
        
        int count=1;
        for(int i=0;i<p.size();i++)
        {
            if(minend>=p[i][0])
            {
              minend=min(minend,p[i][1]);
            }
            else 
            {
                count++;
                minend=p[i][1];
            }
            
        }
        return count;
        
    }
};