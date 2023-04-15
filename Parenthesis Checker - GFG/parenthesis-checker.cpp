//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.size()==0 ||  s[i]=='(' || s[i]=='{' || s[i]=='[' )
            st.push(s[i]);
            
            else if (st.size()>0 )
            {
                if((st.top()=='(' && s[i]==')')  ||  (st.top()=='{' && s[i]=='}') ||
              (st.top()=='[' && s[i]==']'))
                st.pop();
                else if((st.top()!='(' && s[i]==')')  ||  (st.top()!='{' && s[i]=='}') ||
              (st.top()!='[' && s[i]==']'))
                    return false;
            } 
               
        }
        return (st.size()==0);
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends