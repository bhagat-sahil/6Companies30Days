class Solution {
public:
    
    
    bool findWord( int i, string s, unordered_map<string,bool> &map1,  vector<int>&dp )
    {
        if ( i == size(s))  return true ;
        
        if ( dp[i] != -1 ) return (dp[i] == 1)? true : false  ;
        
        string temp = "" ;
        for ( int j = i ; j < size(s) ; j++ )
        {
            temp = temp + s[j] ;
            if ( map1[temp] )
            {
                if (findWord( j+1, s, map1, dp )) 
                {
                    dp[i] = 1 ;
                    return true ;
                }
            }
            
        }
        dp[i] = 0 ;
        return false ;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string,bool> map1 ;
        vector<int>dp(size(s),-1) ;
        
        for ( auto it : wordDict )
            map1[it] = true ;
        
        if ( findWord( 0, s, map1, dp ))    return true ;
        return false ;
    }
};
