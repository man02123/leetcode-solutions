//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> g(26);
        vector<int> indeg(26,0);
        vector<int> found(26,0);
        
        for(int i = 1;i<N;i++){
            string x = dict[i-1];
            string y = dict[i];
            
            int j=0;
            while(j<min(x.size(),y.size()))
            {
                if(x[j]==y[j])
                j++;
                else
                {
                    g[x[j]-'a'].push_back(y[j]-'a');
                    indeg[y[j]-'a']++;
                    found[x[j]-'a']=1;
                    found[y[j]-'a']=1;
                    break;
                }
            }
        }
        for(int i =0;i<26;i++){
            if(found[i] ==0)
            indeg[i]=-1;
            
        }
        queue<int> q;
        string order;
        
        for(int i =0;i<26;i++){
            if(found[i] >0 && indeg[i]==0)
            {
                q.push(i);
                order.push_back(i+'a');
            }
            
        }
       while(!q.empty()){
           
           int node = q.front();
           q.pop();
           
           for(auto it:g[node])
           {
               indeg[it]--;
               if(indeg[it] == 0)
               {
                   order.push_back(it+'a');
                   q.push(it);
               }
           }
       }
    //   for(auto it:order)
    //   cout<<order;
       
       return order;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends