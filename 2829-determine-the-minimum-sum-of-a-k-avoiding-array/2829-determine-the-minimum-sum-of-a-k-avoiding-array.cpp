class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int> mp;
        
        int num = 1;
        int sum = 0;
        
        while(n>0){
          
            if(mp.find(k-num) == mp.end())
            { 
                sum += num;
                mp[num]++;
                n--;
            }
            num++;
        }
        return sum;
        
    }
};