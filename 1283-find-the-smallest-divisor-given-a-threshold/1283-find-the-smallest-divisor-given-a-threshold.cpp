class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        
        int r=*max_element(nums.begin(),nums.end());
        
        int l=1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(check(nums,mid,t)==false)
                l=mid+1;
            else 
                r=mid;
        }
        return l;
    }
bool check(vector<int>& nums,int div,int t)
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=ceil((1.0*nums[i])/div);
        
        // if(nums[i]%div>0)
        //     sum+=(nums[i]/div)+1;
        // else
        //     sum+=(nums[i]/div);
    }
    if(sum>t)
        return false;
    return true;
}
};