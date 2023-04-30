class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
           map<int,int> mp;
           for(auto it:nums)
               mp[it]++;
        
           while(!mp.empty())
           {
               int cnt=0;
               vector<int> temp;
               for(auto it:mp)
               {
                   temp.push_back(it.first);
                   mp[it.first]--;
                   
                   if(mp[it.first]==0)
                       mp.erase(it.first);
                   
                   cnt++;
                   if(cnt==k)
                       break;
               }
               if(temp.size()<k)
               {
                   //cout<<temp.size();
                   return false;
               }
               for(int i=0;i<temp.size();i++)
               {
                   //cout<<temp[i];
                  if(i!=0 && temp[i-1]+1 != temp[i])
                      return false;
               }
               // cout<<" ";
           }
        
        return true;
        
        
        
        
    }
};