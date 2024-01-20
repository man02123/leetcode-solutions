class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n = nums.size();
        
        if(nums.size() <3){
          if(n ==1)return 1;
            return 1;
        }
        sort(begin(nums),end(nums));
        
        int ans = 0;
        
        int i =0,j=n-1;
        
        while(i < j){
            
            int x = nums[i]%nums[j];
            int y =nums[j]%nums[i];
            
            
            if( y < nums[i] && y!=0){
               
                while( i < j){
                    int t = y%nums[j];
                    
                    if( t !=0 && t< nums[i]){
                        j--;
                        y =t;
                    }
                    else break;
                }
                
            }
            else if(nums[i] < nums[j]){
                j--;
            }
            else
                break;
           
        }
        int k = ((j-i+1))%2;
        
        ans = (j-i+1)/2;
        ans +=k;
        if(i> j)return 1;
        return ans;
        
    }
};
//[5,2,2,2,9,10] //1