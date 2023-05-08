class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        
        int tcook = 0;
        double wait = 0;
        
        for(int i = 0;i<c.size() ;i++)
        {
             int atime = c[i][0];
            
            tcook=max(tcook,c[i][0]);
            
            wait+=tcook+c[i][1]-atime;
            
            tcook+=c[i][1];
            
//             int dtime = c[i][1];
            
//             wait+=dtime - atime;
        
            
   
        }
        double ans;
        ans = wait/(c.size());
        return ans;
        
    }
};