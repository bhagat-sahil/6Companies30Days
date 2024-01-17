class Solution {
public:
    
    int dp[51] ;
    
    
    int findAns( int i, string &s, unordered_map<string,int> &mp )
    {
        int n = size(s) ;
        if ( i == size(s))  return 0 ;
        
        
        if ( dp[i] != -1 )    return dp[i] ;
        
        
        string temp = "" ;
        int curExtra ;
        int finalMinExtra = n ;
        
        for ( int curIdx = i ; curIdx < n ; curIdx++ )
        {
            temp.push_back(s[curIdx]) ;
            
            if ( mp.find(temp) == mp.end() )
            {
                curExtra = size(temp) ;
            }
            else curExtra = 0 ;
            
            int nxtExtra = findAns( curIdx+1, s, mp ) ;
            
            int totalExtra = curExtra + nxtExtra ;
            
            finalMinExtra = min( finalMinExtra, totalExtra) ;
            
        }
        return dp[i] = finalMinExtra ;
    
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp ;
        
        
        memset( dp, -1, sizeof(dp)) ;
        for ( auto it : dictionary )
            mp[it]++ ;
        
        return findAns( 0, s, mp ) ;
    
    }
};
