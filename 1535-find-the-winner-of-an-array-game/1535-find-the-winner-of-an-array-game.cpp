class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
     if(k > arr.size())return *max_element(begin(arr),end(arr));
        
       deque<int> dq ={begin(arr),end(arr)};
        //cout<<dq.back()<<dq.front();
        
       int curr= dq.front();
        dq.pop_front();
        int l =0;
       while(1){
           int f = dq.front();
          // cout<<curr<<l<<" ";
           if( f < curr ){
               dq.pop_front();
               dq.push_back(f);
               l++;
               if(l==k)return curr;
           }
           else{
               dq.push_back(curr);
               curr = dq.front();
               dq.pop_front();
               l = 1;
               if(l==k)return curr;
           }
       }
        return -1;
    }
};