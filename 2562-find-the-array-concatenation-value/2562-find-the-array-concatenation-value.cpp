class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        
       long long res=0;
        while(i<=j)
        {
            string temp;
            
            if(i!=j)
            {
                temp+=to_string(nums[i++])+to_string(nums[j--]);
                
            }
            else
            {
                temp+=to_string(nums[i++]);
            }
            res+=stol(temp);   
        }
        return res;
        
        
    }
};