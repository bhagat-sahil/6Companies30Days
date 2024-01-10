class Solution {
public:
    
    
    bool checkPalindrome( string st )
    {
        int s = 0 ;
        int e = st.size()-1 ;
        
        while( s <= e )
        {
            if ( st[s] != st[e] )   return false ;
            
            s++ ;
            e-- ;
        }
        return true ;
    }
    
    
    void findSubsequence( int i, string s1, string s2, string s, int &ans )
    {
        if ( i == s.size() )
        {
            if ( checkPalindrome(s1) && checkPalindrome(s2))
            {
                int temp = s1.length() * s2.length() ;
                ans = max( ans, temp ) ;
            }
            return ;
        }
        
        //when element is in s1
        s1.push_back(s[i]) ;
        findSubsequence( i+1, s1, s2, s, ans ) ;
        s1.pop_back() ;
        
        //when element is in s2
        
        s2.push_back(s[i]) ;
        findSubsequence( i+1, s1, s2, s, ans ) ;
        s2.pop_back() ;
        
        //element skip
        
        findSubsequence( i+1, s1, s2, s, ans ) ;
        
    }
    
    int maxProduct(string s) 
    {
        
        int ans = 0 ;
        string s1 = "" ;
        string s2 = "" ;
    
        findSubsequence( 0, s1, s2, s, ans ) ;
        return ans ;
    }
};
