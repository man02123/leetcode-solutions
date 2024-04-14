class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
       int n = nums.size();
       
        int i =0 , j = n-1;
        
        while(i < n){
            if(is_prime(nums[i]))break;
            i++;
        }
         while( j>=0){
            if(is_prime(nums[j]))break;
            j--;
        }
      // cout<<is_prime(3);
        return j-i;
        
    }
    
    bool is_prime(int n){
        
        bool ans = true;
        if(n==1 )return false;
        
        for(int i =2;i<n;i++){
            if(n%i == 0)return false;
        }
        return true;
    }
};