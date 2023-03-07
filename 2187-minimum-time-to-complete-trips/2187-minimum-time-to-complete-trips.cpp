class Solution {
public:
    // long long minimumTime(vector<int>& t, int total) {
//         long long int u=0;
        
// //        for(int i=0;i<t.size();i++)
// //        {
// //            if((long long int)t[i]>u)
// //                u=t[i];
// //        }
//         long long int l=1;
//         long long int r = 1e14;
//         while(l<r)
//         {
//             long long int mid=l + (r-l)/2;
//             if(check(t,total,mid)>=total)
//                 r=mid;
//             else
//                 l=mid+1;
                
//         }
//         return l;
        
//     }
//     long long int check(vector<int>& t,int total,int start)
//     {
//         long long int totaltrip=0;
        
//         for(auto it:t)
//         {
//             long long int val=it;
//             totaltrip+=(start)/val;
//         }
        
        
//         return totaltrip;
        
//     }
        
        
// };



long long int numberOfTripsForGivenTime(vector<int>&a , long long int givenTime)
    {
        long long int totalTrips = 0;
        for(auto x : a)
        {
            // convert it to long long int 
            long long int val = x;
			
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& arr ,  int totalTrips) {
        long long int lowestTime = 1;
        long long int highestTime = 1e14;
        while(lowestTime<highestTime)
        {
            long long int mid = lowestTime + (highestTime-lowestTime)/2;
            
            if(numberOfTripsForGivenTime(arr , mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid+1;
        }
        return lowestTime;
    }
};