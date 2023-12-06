class Solution {
public:
    int totalMoney(int n) {
        int f = 0;
        int ans =0;
        int k =n/7;
        while(k>=0){
            f++;
           
            int t =f;
            for(int j =1;j<=7 && n>0;j++){
                ans += t++;
                n--;
            }
            k--;
        }
        return ans;
    }
};