class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
         
        
        int sz = arr.size();
        
       // vector<int> c = {arr[n/4],arr[n/2],arr[(n*3)/4]};
        vector<int> ca = {arr[sz/4], arr[sz/2], arr[sz*3/4]};
        for(auto it:ca){
            
            int num = it;
            auto lb = lower_bound(arr.begin(),arr.end(),num);
            auto ub = upper_bound(arr.begin(),arr.end(),num);
           // cout<<distance(ub,lb)<<distance(lb,ub);
            if(4*distance(lb,ub) >arr.size()  )
                return it;
        }
        return -1;
    }
};