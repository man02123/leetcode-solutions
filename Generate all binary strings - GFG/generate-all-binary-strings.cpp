//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num){
        string temp;
        gen(num,temp);
    }
    void gen(int num,string temp)
    {
        if(num==0)
        {
            for(auto it:temp)
            cout<<it;
            cout<<" ";
            return;
        }
        string x=temp;
        
        x.push_back('0');
        gen(num-1,x);
        
        if(temp.size()==0)
        {
            temp.push_back('1');
            gen(num-1,temp);
        }
        
       else if(temp.size()>0 && temp.back()!='1')
        {
            temp.push_back('1');
            gen(num-1,temp);
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends