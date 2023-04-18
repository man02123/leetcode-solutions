
class Solution {
public:
    int countGoodNumbers(long long n) {
       int m = 1e9+7;
      return (cnt(5,(n+1)/2,m)*cnt(4,n/2,m))%m;
    }
    long long cnt(int option,long long num,int m)
    {
        if(num==0)
            return 1;
        long long x=cnt(option,num/2,m);
        
         if(num%2==0)
            return (x*x)%m;
        else 
        {
            return (((option*x)%m)*x)%m;
        }
    }
};
// class Solution {
// public:
//     long long powerMod(int a, long long b, int mod) {
//         if(b == 0)
//             return 1;
//         long long x = powerMod(a, b/2, mod);
//         if(b % 2 == 0)
//             return (x * x) % mod;
//         else
//             return (((a * x) % mod) * x) % mod;
//     }
    
//     int countGoodNumbers(long long n) {
//         int mod = 1e9+7;
//         return (powerMod(5, (n + 1) / 2, mod) * powerMod(4, n / 2, mod)) % mod;
//     }
// };