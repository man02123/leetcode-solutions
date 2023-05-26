//#define pair<int,int> pi

class Solution {
public:
    
    static bool comp(vector<int>&a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& t, int cap) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        sort(t.begin(),t.end(),comp);
        // for(auto it:t)
        //     cout<<it[1];
        
        int maxi = INT_MIN;
        int currsum = 0;
        for(int i = 0 ;i < t.size() ;i++)
        {
           while(pq.size()>0 && pq.top().first<=t[i][1])
           {
               currsum -=pq.top().second;
               pq.pop();
               
           }
            currsum+=t[i][0];
            maxi = max(maxi,currsum);
            //cout<<currsum;
            
            pq.push({t[i][2],t[i][0]});   
            
        }
        
        if(maxi>cap)
            return false;
        return true;
        
        

        
    }
};