class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int x=*max_element(w.begin(),w.end());
        
        int sum=0;
        for(int i=0;i<w.size();i++)
            sum+=w[i];
        

        
        int l=x,r=sum;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(check(w,mid,d)==true)
                r=mid;
            else
                l=mid+1;    
        }
        return l;
        
        
    }
    bool check(vector<int>& w,int cap,int day)
    {
        int i=0;
        int sum=0;
        int daysneed=1;
       for(int i=0;i<w.size();i++)
       {
               sum+=w[i];
           if(sum>cap)
           {
               sum=w[i];
               daysneed++;
           }
       }
        
        
        return daysneed<=day;
    }
};