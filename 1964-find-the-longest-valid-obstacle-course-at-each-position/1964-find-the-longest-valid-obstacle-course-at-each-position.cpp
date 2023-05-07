class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        vector<int> lis(o.size(),1);
        
        vector<int> temp;
        
        for(int i = 0;i<o.size();i++)
        {
            int ind = upper_bound(temp.begin(),temp.end(),o[i]) - temp.begin();
           
            if(ind==temp.size())
            {
                
                    temp.push_back(o[i]);
                    lis[i]=temp.size();
            }
            
            else
            {
                temp[ind] = o[i];
                lis[i]=ind+1;
            }
        }
        return lis;
        
    }
};