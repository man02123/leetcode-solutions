class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        
        vector<int> clr(n+1,0);
            
        vector<int> res;
        int clrcnt = 0;
        
        
        for(int i = 0;i<q.size();i++)
        {
         
            if(i ==0)
            {
                res.push_back(0);
                clr[q[i][0]] = q[i][1];
            }
            else
            {
              
                if(clr[q[i][0]] ==0)
                {
                    clr[q[i][0]] =q[i][1];
                    if(q[i][0]-1 >=0 && clr[q[i][0]-1] ==q[i][1])
                        clrcnt++;
                    
                    if(q[i][0]+1 <n && clr[q[i][0]+1] ==q[i][1])
                        clrcnt++;
                    res.push_back(clrcnt);
                    
                }
                else
                {
                    int plr = clr[q[i][0]];
                    
                    if(q[i][0]-1 >=0 && clr[q[i][0]-1] ==plr && clrcnt>0)
                        clrcnt--;
                    
                    if(q[i][0]+1 >=0 && clr[q[i][0]+1] ==plr && clrcnt>0)
                        clrcnt--;
                    
                     clr[q[i][0]] =q[i][1];
                    if(q[i][0]-1 >=0 && clr[q[i][0]-1] ==q[i][1])
                        clrcnt++;
                    
                    if(q[i][0]+1 <n && clr[q[i][0]+1] ==q[i][1])
                        clrcnt++;
                    
                    res.push_back(clrcnt);
                    
                }
                   
                
            }
                
            
            
        }
        
       return res; 
    }
};