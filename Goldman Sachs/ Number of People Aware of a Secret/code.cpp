class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        int mod = 1e9+7 ;
        vector<int>day(3001,0) ;
        day[1] = 1 ;
        
        
        for ( int i = 1 ; i < n ; i++ )
        {
            for ( int j = i + delay ; j < i + forget ; j++ )
            {
                day[j] = (day[i] + day[j]) % mod ;
            }
        }
        long long ans = 0 ;
        for ( int i = n - forget+1 ; i <= n ; i++ )
        {
            ans = (ans + day[i]) % mod ;
        }
        return ans ;
    }
};
