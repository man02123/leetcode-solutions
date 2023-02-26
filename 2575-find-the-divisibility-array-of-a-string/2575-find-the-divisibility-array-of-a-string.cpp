class Solution {
public:
    vector<int> divisibilityArray(string w, int m) {
        long long currrem=0;
        vector<int> res;
        for(int i=0;i<w.size();i++)
        {
            currrem=currrem*10+(w[i]-'0');
            if(currrem%m==0)
            {
                res.push_back(1);
                currrem=0;
            }
            else
            {
                res.push_back(0);
                currrem=currrem%m;
            }
        }
        return res;
    }
};