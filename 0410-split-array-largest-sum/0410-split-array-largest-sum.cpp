class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0, r = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        
        while(l<r){
            int mid = l+(r-l)/2;
            
            if(check(nums , k ,mid)){
                ans = mid;
                r = mid;
            }
            else
                l = mid+1;
        }
        if(k==1)
            return accumulate(nums.begin(),nums.end(),0);
        
        return ans;
        
    }
    int check(vector<int>& nums  , int part , int mid){
        
        int currpart = 0;
        int csum = 0;
        int mx = 0;
        
        for(int i =0;i<nums.size();i++){
            if(mid < nums[i])
                return false;
            
            if(nums[i]+csum > mid){
                currpart++;
                csum = nums[i];
                mx = max(csum , mx);
            }
            else{
                csum += nums[i];
                mx = max(csum , mx);
            }
        }
        //cout<<mx<<mid<< " ";
        currpart++;
        
        // if(mx > mid)
        //     return false;
        
        if(currpart <= part)
            return true;
        
        return false;
        
    }
};