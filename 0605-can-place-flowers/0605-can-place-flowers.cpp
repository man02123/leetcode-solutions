class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        if(f.size() == 1 && f[0] ==0 && n<=1)
            return true;
        if(f.size()<n/2)
            return false;
        
        for(int i = 0;i<f.size();i++)
        {
            if(f[i] == 1)
                i++;
            else if(i == f.size()-1 && i-1>=0 && f[i-1]!=1 && f[i]==0)
                n--;
            else if(f[i] == 0 && i+1<f.size() && f[i+1]!=1) 
            {
                        f[i]=1;
                        n--;
                        i++;
            }
        }
        //cout<<n;
        if(n<=0)
            return true;
        return false;
        
    }
};