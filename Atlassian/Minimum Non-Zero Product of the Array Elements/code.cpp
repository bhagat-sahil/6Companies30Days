class Solution {
public:
    long long solve( long long k, long long n, long long mod )
    {
        if ( n == 0 ) return 1;
        
        if ( n == 1 ) return k;
        
        
        long long ans = solve( k, n/2, mod)%mod ;
        
        ans = ( ans*ans )%mod ;
        
        if ( n ) 
            ans = ((ans%mod)*(k%mod))%mod ;
        
        return ans ;
    }
    
    int minNonZeroProduct(int p) 
    {
        long long mod = 1e9+7 ;
        long long b = pow(2,p) ;
        long long k = b-2 ;
        
        int ans = solve( k, (k+1)/2, mod ) % mod ;
        ans = ( (ans%mod)*((b-1)%mod) )% mod ;
        return ans ;
    }
};
