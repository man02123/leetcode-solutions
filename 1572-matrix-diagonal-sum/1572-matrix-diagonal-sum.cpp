class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=0;
        int sum=0;
        
        while(i<mat.size()  && j<mat[0].size())
        {
            sum+=mat[i][j];
            mat[i][j]=-1;
            i++;
            j++;
        }
        
        i=mat.size()-1;
        j=0;
        while(i>=0 && j<mat[0].size())
        {
            if(mat[i][j]!=-1)
                sum+=mat[i][j];
            i--;
            j++;

        }
        
        return sum;
    }
};