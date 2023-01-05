class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),comp);
        
       // int start=in[0][0];
        int end=in[0][1];
        int count=0;
        
        for(int i=1;i<in.size();i++)
        {
            if(end>in[i][0] )
            {
                count++;
                
                if(end<=in[i][1])
                end=min(end,in[i][1]);
            }
            else 
            {
                end=in[i][1];
            }
        }
        return count;
    }
};