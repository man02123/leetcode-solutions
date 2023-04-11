class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       
        
        set<vector<int>> st;
        
        for(int i=0;i<=n-3;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                }
                
                    else if(nums[i]+nums[l]+nums[r]>0)
                        r--;
                    else
                    l++;
            }   
        }
        vector<vector<int>> res={st.begin(),st.end()};
        return res;
        
    }
};