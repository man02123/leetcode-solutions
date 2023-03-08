class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
        int r=*max_element(p.begin(),p.end());
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(check(p,mid,h))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
    bool check(vector<int>& p,int total,int minh)
    {
        int hours=0;
        for(int i=0;i<p.size();i++)
        {
            if((p[i]%total)!=0)
                hours+=(p[i]/total)+1;
            else
              hours+=(p[i]/total);  
        }
    
    if(hours<=minh)
        return true;
    return false;
    }
};