/*

Description:

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) 
        {
            return 0;
        }
        
        bool prime[n];
        memset(prime, true, n*sizeof(bool));
        prime[0] = false;
        prime[1] = false;
        
        int res = 0;  
        int limit = sqrt(n);
        for(int i = 2; i <= limit; i++)
        {
            if(prime[i])
            {
                for(int j = i*i; j < n; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
             if(prime[i])
             {
                 res++;
             }
        }
       return res; 
    }
};