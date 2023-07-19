class Solution {
public:
    int a,b,c,d;
    bool makesquare(vector<int>& m) {
        int sum = 0;
        for(auto it:m)sum+=it;
        
        if(sum%4 !=0)
          return false;
        
        int x= sum/4;
        
        a =x,b=x,c=x,d=x;
        
        //cout<<a<<b;
        sort(m.rbegin(),m.rend());
        
        return solve(m,0);
    }
    bool solve(vector<int>& m , int ind)
    {
        if(ind>m.size())
            return false;
        
        if(ind == m.size())
        {
            if(d==0 && b==0 && c==0 && a==0)
                return true;
            
            return false;
        }
        //cout<<ind;
       
        if(m[ind]<=a)
        {
            a-=m[ind];
            if(solve(m,ind+1))
                return true;
            a += m[ind];
        }
         if(m[ind]<=b)
        {
            b-=m[ind];
            if(solve(m,ind+1))
                return true;
            b += m[ind];
        }
         if(m[ind]<=c)
        {
            c-=m[ind];
            if(solve(m,ind+1))
                return true;
            c += m[ind];
        }
         if(m[ind]<=d)
        {
            d-=m[ind];
            if(solve(m,ind+1))
                return true;
            d += m[ind];
        }
        
        
        
        return false;
        
    }
};