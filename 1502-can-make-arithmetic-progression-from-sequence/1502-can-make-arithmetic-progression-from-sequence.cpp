class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        vector<int> rarr = arr;
        reverse(rarr.begin(),rarr.end());
            bool ans1 = true,ans2=true;
        
        int d = arr[1]-arr[0];
        
        for(int i = 1;i<arr.size();i++)
          if(arr[i]-arr[i-1] != d)
              ans1  = false;
        
        
        d = rarr[1]-rarr[0];
        for(int i = 1;i<arr.size();i++)
          if(rarr[i]-rarr[i-1] != d)
              ans2 = false;
        
        return ans1|ans2;
    }
};