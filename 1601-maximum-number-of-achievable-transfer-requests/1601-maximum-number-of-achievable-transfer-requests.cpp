class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& re) {
        vector<int> bstate(n);
        return solve(re,bstate,0);
    }
    int solve(vector<vector<int>>& re ,vector<int> &bstate,int ind )
    {
        if(ind>=re.size())
        {
            //bool valid  =true;
            int ans = 0;
           for(auto it:bstate)
           {
             if(it!=0)
                 return INT_MIN;
           }
           
            return 0;
        }
        
        bstate[re[ind][0]]--;
        bstate[re[ind][1]]++;
        int trans = 1+solve(re,bstate,ind+1);
        
        bstate[re[ind][0]]++;
        bstate[re[ind][1]]--;
        int notrans = solve(re,bstate,ind+1);
        
        return max(trans,notrans);
        
    }
};