class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>friends(n) ;
        for ( int i = 0 ; i < n ; i++ )
            friends[i] = i ;
        
        int i = 0 ;
        while ( friends.size() > 1 )
        {
            i = i + k - 1 ;
            if ( i >= friends.size() )
            {
                i = i % friends.size() ;
                friends.erase(friends.begin() + i ) ;
                
            }
            else
            {
                friends.erase( friends.begin() + i ) ;
                
            }
        }
        return friends[0] + 1 ;
    }
};
