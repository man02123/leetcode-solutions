//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res;
    vector<int> dx;
    vector<int> dy;
    string dir;
    vector<string> findPath(vector<vector<int>> &m, int n) {
        dx={1,0,-1,0};
        dy = {0,1,0,-1};
        dir="DRUL";
       string temp;
        recur(m,0,0,temp);
       return res;
    }
    void recur(vector<vector<int>> &m,int r,int c,string &temp)
    {
        // cout<<r<<c;
        // cout<<endl;
        if(r==m.size()-1 && c==m[0].size()-1 && m[r][c]!=0 )
            {
                res.push_back(temp);
                return ;
            }
        
        if(r>=m.size()  || r<0 || c>=m[0].size() || c<0 || m[r][c]==0 || m[r][c]==-1)
            return ;
        
        
        
        for(int i=0;i<4;i++)
        {
            temp.push_back(dir[i]);
            int nx=r+dx[i];
            int ny=c+dy[i];
            int x=m[r][c];
            m[r][c]=-1;
            
            recur(m,nx,ny,temp);
            m[r][c]=x;
            
            temp.pop_back();
        }
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends