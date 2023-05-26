class Solution {
public:
    static bool comp(vector<int>&a,vector<int> &b)
    {
        return a[1]>b[1];
    }
    bool carPooling(vector<vector<int>>& t, int cap) {
        map<int,vector<int>> end,start;
        
        for(int i=0;i<t.size();i++)
        {
            end[t[i][2]].push_back(t[i][0]);
            start[t[i][1]].push_back(t[i][0]);
        }
        //vector<vector<int>> in ;
        int maxi = INT_MIN;
        int currsum = 0;
        for(int i =0;i<1000;i++)
        {
           if(start.find(i)!=start.end())
           {
               for(auto it:start[i])
                   currsum+=it;
           }
            if(end.find(i)!=end.end())
           {
               for(auto it:end[i])
                   currsum-=it;
           }
            maxi  = max(currsum,maxi);
            
        }
        if(maxi>cap)
            return false;
        return true;
        
        
        
//         in.push_back({t[1],t[2]});
//         for(int i=1;i<t.size();i++)
//         {
//             if(in.back()[1]>t[i][1])
//                 in.push_back({t[i][1],t[i][2]});
            
//             else if()
            
//         }
        
        
    }
};