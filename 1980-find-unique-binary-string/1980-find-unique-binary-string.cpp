class Solution {
public:string res;
    unordered_set<string> st;
    string findDifferentBinaryString(vector<string>& nums) {
        
        for(auto it:nums)st.insert(it);
        string temp;
        permute(temp,nums.size());
        return res;
    }
    void permute(string s ,int n)
    {
        if(s.size()>n)return;
        
        if(s.size()==n && st.find(s)==st.end())
        {
            res=s;
            return;
        }
        string t=s;
        t.push_back('0');
        permute(t,n);
       
        s.push_back('1');
        permute(s,n);
    }
};