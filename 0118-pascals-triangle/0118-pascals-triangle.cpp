class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans;
        if(n == 1)
            return {{1}};
        
        if(n==2)
            return {{1},{1,1}};
        
        ans.push_back({1});
        ans.push_back({1,1});
        
        vector<int> temp = {1,1};
       
        
        int i = 2;
        while(n-i>0){
            vector<int> x(i+1,1);
            
            for(int  j= 1 ;j < i ;j++){
                x[j] = temp[j]+temp[j-1];
            }
             
            ans.push_back(x);
            temp = x;
            //cout<<i<<" ";
            i++;
            
        }
        return ans;
        
    }
};