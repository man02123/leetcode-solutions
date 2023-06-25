class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans12 =0;
        
        for(int i =0;i<nums.size();i++){
            
            for(int j =i+1;j<nums.size();j++)
            {
                string y =to_string(nums[i]);
                string x = to_string(nums[j]);
                int lst = x.back()-'0';
                int fst = y[0]-'0';
            
                
                if(__gcd(lst,fst)==1)ans12++;
            }
        }
        return ans12;
        
    }
};