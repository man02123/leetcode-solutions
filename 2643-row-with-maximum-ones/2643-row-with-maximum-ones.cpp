class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> res;
        int num=0;
        int rrow=0;
        int i=0,cnt=0;
        for(;i<mat.size();i++)
        {
            cnt=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                    cnt++;
            }
            if(num<cnt)
            {
                num=cnt;
                rrow=i;
            }
        }
        
        res={rrow,num};
        return res;
    }
};