// class Solution {
// public:bool flag;
//     int makeArrayIncreasing(vector<int>& arr1, vector<int>& a) {
//         flag=false;
//         sort(a.begin(),a.end());
//         long long ans =solve( arr1 ,a, 0,0);
        
//         // if(flag==true)
//         //     return ans;
//         // return -1;
        
//             if(ans <-1)return -1;
//         return ans;
        
        
//     }
//     long long  solve(vector<int>& arr1 ,vector<int>& a,int ind,int prev ){
        
//         if(ind>=arr1.size()){
//             return 0;  
//         }
//         int pos = upper_bound(a.begin(),a.end(),prev)-a.begin();
        
//         if(arr1[ind]>prev){
//             long long  rep = INT_MAX;
//             if(pos>=0 && pos<a.size()){
//              rep = 1+solve(arr1,a,ind+1,a[pos]);
//             }
//             long long nonrep = solve(arr1 , a , ind+1, arr1[ind]);
//             return min(rep,nonrep);   
//         }
//         else{
//             if(pos==a.size())
//                 return INT_MAX; 
//             else if(pos>=0 && pos<a.size()){
//                 return 1+solve(arr1 , a,ind+1,a[pos]);
//             }
//         }

//         return INT_MAX;
        
//     }
// };

class Solution {
private:

int check(int curr, int left, vector<int>& arr1 ,vector<int>& arr2, vector <unordered_map<int,int> >& dp)
{
          if (curr == arr1.size())
            return 0;

          if (dp[curr].find(left) != dp[curr].end())
            return dp[curr][left];

          int exclude,include;

        // exclude stores the no. of ways for making array strictly 
       // increasing when not replacing the current element 

     // include stores the no. of ways for making the array strictly
    // increasing after replacing the current element


        if (arr1[curr] > left)    
            exclude = check(curr+1, arr1[curr], arr1, arr2, dp);
    
         else
            exclude = INT_MAX;

         int rep = upper_bound(arr2.begin(),arr2.end(), left) - arr2.begin();

           if (rep == arr2.size())
             include = INT_MAX;

           else
            include = check(curr+1, arr2[rep], arr1, arr2, dp);

             if (include == INT_MAX)
                dp[curr][left] = exclude;

             else
                dp[curr][left] = min(exclude,include+1);

    return dp[curr][left];
}

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
           sort(arr2.begin(), arr2.end());
           vector <unordered_map<int,int> > dp(2001);  

           int val = check(0, INT_MIN, arr1, arr2, dp);

        // if the value is INT_MAX than that means the array can not
      //   be strictly increasing by replacing any number of element

            if (val == INT_MAX)
                return -1;

        return val;
    }
};