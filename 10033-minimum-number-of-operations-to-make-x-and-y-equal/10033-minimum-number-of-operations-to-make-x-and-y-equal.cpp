#define t pair<int,int> 
class Solution {
public:
    int n;
    //int dp[10001];
   
    int minimumOperationsToMakeEqual(int x, int y) {
        n = y;
        //memset(dp,-1,sizeof(dp));
         set<int>st;
        queue<t> q;
        
        q.push({x,0});
        int ans = abs(x-y);
        
        while(q.size() >0){
            
            int num = q.front().first;
            int op = q.front().second;
           
            //if(num>10000)break;
            q.pop();
            
            if(num == y){
                ans = min(ans,op);
                break;
            };
             
            //st.insert(num);
            if(num < n){
                ans = min(ans,op + abs(n-num));
            }
                else{
            if(num %11 ==0){
                st.insert(num/11);
                q.push({ num/11,op+1});
            }
            if(num %5 ==0){
                st.insert(num/5);
                q.push({ num/5,op+1 });
            }
                if(st.find(num-1)==st.end())
                q.push({num-1,op+1 }),st.insert(num-1);
                
                if(st.find(num+1)==st.end())
                q.push( {num+1,op+1}),st.insert(num+1);
        
    }
            
            
    }
        return ans;
        
    }
        
        // return solve(x);
        // }
//     int solve(int num){
//         if(num < n)return (abs(n-num));
        
//         if(num >= 10000)return abs(n-num);
//         if(num == n)return 0;
//         if(dp[num]!=-1)return dp[num];
//         int ans = abs(n-num);
        
//         if(num %11 ==0 && st.find(num/11)==st.end() ){
//             st.insert(num/11);
//             ans = min(ans,1+solve(num/11));    
//         }
//         if(num %5 ==0 && st.find(num/5)==st.end()){
//             st.insert(num/5);
//         ans = min(ans,1+solve(num/5));  
//         }
        
//         if(st.find(num-1)==st.end()){
//             st.insert(num-1);
//             ans = min(ans, 1+solve(num-1));
//         }
        
//         if(st.find(num+1)==st.end()){
//             st.insert(num+1);
//             ans = min(ans, 1+solve(num+1));
//         }
        
        
//         return dp[num]=ans;
//     }
 };

//1
//19
//89
//57