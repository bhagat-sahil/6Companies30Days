class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int bulls = 0 ;
        int cows = 0 ;
        unordered_map<char,int>m1 ;
        unordered_map<char,int>m2 ;
        
        for ( int i = 0 ; i < secret.size() ; i++ )
        {
            if ( secret[i] == guess[i] )    bulls++ ;
            
            else{
                m1[secret[i]]++ ;
                m2[guess[i]]++ ;
            }
        }
        
        for ( auto it : m2 )
        {
            if ( m1.find(it.first) != m1.end() )
                cows = cows + min( m1[it.first], m2[it.first]) ;
        }
        return to_string(bulls) + "A" + to_string(cows) + "B" ;
    }
};
