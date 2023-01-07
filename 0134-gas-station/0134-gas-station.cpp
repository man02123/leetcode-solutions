class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int sum=0;
        int ind=0;
        int totalsum=0;
        for(int i=0;i<g.size();i++)
        {
            totalsum+=g[i]-c[i]; 
            sum+=g[i]-c[i];
            if(sum<0)
            {
                ind=i+1;
                sum=0;
            }
            
            
        }
        if(totalsum<0)return -1;
        
        return ind;
    }
};