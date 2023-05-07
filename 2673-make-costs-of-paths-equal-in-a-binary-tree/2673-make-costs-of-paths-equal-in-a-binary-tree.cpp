class Solution {
public:
    int mini;
    int minIncrements(int n, vector<int>& cost) {
        mini = 0;    
     calcsum(cost,1);
        // if(cost.size()>=3)
        //     mini+=abs(cost[1]-cost[2]);
        
     return mini;
    }
    int calcsum(vector<int>& c,int ind)
    {
        if(ind>c.size())
            return 0;
        
       //cout<<ind<<" ";
        
        //mini+=abs(c[2*ind+1]-c[2*ind+2]);
        //cout<<c[2*ind+1]<<c[2*ind+2];
        //cout<<abs(c[2*ind]-c[2*ind+1]);

       int l =  calcsum(c,2*ind);
        int r  = calcsum(c,2*ind+1);
        mini+=abs(l-r);
        
        return max(l,r)+c[ind-1];
          
        
    }
//     void calcres(vector<int>& c,int ind,int currlvl)
//     {
//         if(ind>c.size())
//             return ;
//         if(currlvl == lvl)
//         {
//             cout<<ind<<mini-c[ind]<<" ";
//             res+=mini-c[ind];
//             return;
//         }
//       //currlvl
//         calcres(c,2*ind+1,currlvl+1);
//         calcres(c,2*ind+2,currlvl+1);
        
        
//     }
};