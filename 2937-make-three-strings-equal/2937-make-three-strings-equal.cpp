class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1==s2 && s2==s3)return 0;
        
        int ans = 0;
        for(int i =0;i<min({s1.size(),s2.size(),s3.size()});i++){
            if(s1[i] == s2[i] && s2[i]==s3[i]){
                ans++;
            }
            else
                break;
        }
        if(ans <1)return -1;
        
        return (s1.size()+s2.size()+s3.size())-(ans*3);
    }
};