class Solution {
public:vector<string> res;
    int x;
    vector<string> generateParenthesis(int n) {
        x=n;
        recur(2*n,"",0,0);
        return res;
    }
    void recur(int n,string temp,int open,int close)
    {
        if(n==0 && open==x && close==x)
        {
            res.push_back(temp);
            return;
        }
        //cout<<n;
        if(open>=close && open<=x)
        {
            temp.push_back('(');
                recur(n-1,temp,open+1,close);
            temp.pop_back();
            
            temp.push_back(')');
                recur(n-1,temp,open,close+1);
            
        }
        
        
        
    }
};