class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int x = msort(nums,0,nums.size()-1);
        return x;
    }
    int msort(vector<int>& nums,int l,int r)
    {
        if(l>=r)
            return 0;
        long long cnt = 0,mid;
        mid = (l)+(r-l)/2;
        
        cnt +=msort(nums,l,mid);
        cnt +=msort(nums,mid+1,r);
        return cnt+merge(nums,l,mid,r);
        
    }
    int merge(vector<int>& nums,int l,int mid,int r)
    {
        vector<int> temp;
        int i= l,j =mid+1;
        int cnt =0;
        
        while(i<=mid)
        {
            while(j<=r && nums[i]>2*(long long)nums[j])
                j++;
            
                cnt+=j-(mid+1);
            i++;
        }
  //       for (int i = l; i <= mid; i++) {
  //   while (j <= r && nums[i] > 2  * (long long)nums[j]) {
  //     j++;
  //   }
  //   cnt += (j - (mid + 1));
  // }
        i=l;
        j=mid+1;
        while(i<=mid && j<=r)
        {
            if(nums[i]>nums[j])
            {
                temp.push_back(nums[j]);
                j++;
            }
            else
            {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid)
        {
          temp.push_back(nums[i]);
                i++;  
        }
        while(j<=r)
        {
            temp.push_back(nums[j]);
                j++;
        }
        
        for(int i=l;i<=r;i++)
        {
            nums[i] =temp[i-l];
        }
        return cnt;
    }
};