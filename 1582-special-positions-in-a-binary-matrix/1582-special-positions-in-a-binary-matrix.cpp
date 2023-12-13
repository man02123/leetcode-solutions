class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> r(mat.size());
        vector<int> c(mat[0].size());
        int n = mat.size(),m = mat[0].size();
        
        for(int i =0;i<n;i++){
            int sum = 0;
            for(int j =0;j<m;j++){
                sum += mat[i][j];
            }
            r[i]  =sum;
        }
        
        for(int j =0;j<m;j++){
            int sum = 0;
            for(int i =0;i<n;i++){
                sum += mat[i][j];
            }
            c[j]  =sum;
        }
        
        int ans =0 ;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 1 && r[i]==1 && c[j]==1)ans++;
            }
        }
        return ans;
    }
};