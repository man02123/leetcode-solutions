class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        
        bool ans = false;
        for(int i=0;i<4;i++)
        {
            rev(mat);
            if(mat==tar)
                return true;
        }
        return false;
    }
    void rev(vector<vector<int>>& mat)
    {
        int m=mat.size();
        int n = mat[0].size();
    for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(i>j)
                    swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<m;i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};