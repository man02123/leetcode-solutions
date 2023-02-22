class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int x=*max_element(begin(q),end(q));
        
        int l=1,r=x;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(check(q,mid,n)==false)
                r=mid;
            else
                l=mid+1;
        }
        return l;
        
    }
    bool check(vector<int>& nums,int maxprd,int tshop)
    {
        int currsh=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%maxprd>0)
            currsh+=(nums[i]/maxprd)+1;
            else
             currsh+=(nums[i]/maxprd);   
        }
        if(currsh<=tshop)
            return false;
        return true;
    }
};