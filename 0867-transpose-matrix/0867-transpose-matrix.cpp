class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        vector<vector<int>> m(mat[0].size(),vector<int>());
        for(int j =0;j<mat[0].size();j++){
            int k =0;
            for(int i=0;i<mat.size();i++){
                m[j].push_back( mat[i][j]);
                //cout<<k;
            }
        }
        return m;
    }
};