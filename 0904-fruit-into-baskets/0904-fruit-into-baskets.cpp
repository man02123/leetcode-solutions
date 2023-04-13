class Solution {
public:
    int totalFruit(vector<int>& fr) {
        int res=0;
        int i=0,j=0;
        unordered_map<int,int> mp;
        
        int k=2;
        for(int i=0;i<fr.size();i++)
        {
            while(j<fr.size())
            {
                if(mp[fr[j]]>0)
                {
                    res=max(res,j-i+1);
                    mp[fr[j]]++;
                    j++;
                }
                else if(mp[fr[j]]==0 && k>0)
                {
                    mp[fr[j]]++;
                    k--;
                    res=max(res,j-i+1);
                    j++;
                }
                else if(mp[fr[j]]==0 && k==0)
                    break;
            }
            mp[fr[i]]--;
            if(mp[fr[i]]==0)
            {
                mp.erase(fr[i]);
                k++;
            }
        }
        return res;
        
        
    }
};