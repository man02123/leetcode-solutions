class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> flipped;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0){
                if(flipped.size()==0  || flipped.size()%2==0 )
                {
                    if(i+k>nums.size())
                        return -1;
                    ans++;
                 flipped.push(i+k-1);   
                }
                
            }
            else
            {
                if(flipped.size()%2==1){
                    if(i+k>nums.size())
                        return -1;
                    flipped.push(i+k-1);
                    ans++;
                }
            }
            if(flipped.size()>0 && i>=flipped.front())flipped.pop();
        }
        return ans;
    }
};