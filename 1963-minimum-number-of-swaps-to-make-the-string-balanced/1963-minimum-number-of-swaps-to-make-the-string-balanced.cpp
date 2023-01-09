class Solution {
public:
    int minSwaps(string s) {
        int right=0;
        int swapcount=0;
        
        for(auto it:s)
        {
            if(it=='[')
                right++;
            
            else if(right>0)
                right--;
            
            
        }
       
        
            return (right+1)/2;;
        
    }
};