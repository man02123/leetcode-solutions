class Solution {
public:
    int countSeniors(vector<string>& d) {
        string temp;
        int cnt = 0;
        
        for(auto it:d)
        {
            string s =it;
            int x =s[11]-'0';
            int y = s[12]-'0';
            if(10*x+y>60)
                cnt++;
        }
        return cnt;
        
    }
};