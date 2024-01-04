class Solution {
public:
    
    long long findDifferentWays( int step, int startPos, int endPos, int totStep, vector<vector<long long>>&dp )
    {
        if ( step  == totStep && startPos == endPos )   return 1 ;
        
        
        if ( step > totStep || startPos > endPos + totStep )    return 0 ;
        
        if ( dp[step][startPos+1000] != -1 )     return dp[step][startPos+1000] ;
        
        long long left = findDifferentWays( step+1, startPos-1, endPos, totStep, dp ) ;
        
        long long right = findDifferentWays( step+1, startPos+1, endPos, totStep, dp ) ;
        
        return dp[step][startPos+1000] = (left + right)%1000000007 ;
    }
    
// 10 11
// 2 3 4 5 6 7 8 9 10 11 12
    int numberOfWays(int startPos, int endPos, int k)
    {
        vector<vector<long long>>dp( startPos+k+1, vector<long long>( 3001,-1 )) ;
        long long ans = findDifferentWays( 0, startPos, endPos, k, dp ) ;
        return ans%1000000007 ;
        
    }
};
