class Solution {
public:int cnt;
    
    int subsetXORSum(vector<int>& nums) {
        cnt=0;
        vector<int> temp;
         gsub(nums,0,temp);
        return cnt;
    }
    void gsub(vector<int>& nums,int ind,vector<int> &temp)
    {
        if(ind>nums.size())
            return;
        if(ind==nums.size())
        {
            int res=0;
            for(auto it:temp)
            {
                res^=it;
            }
            cnt+=res;
            return;
        }
        temp.push_back(nums[ind]);
        gsub(nums,ind+1,temp);
        temp.pop_back();
        gsub(nums,ind+1,temp);
    }
};