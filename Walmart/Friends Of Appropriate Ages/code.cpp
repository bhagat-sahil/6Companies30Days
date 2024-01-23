class Solution {
public:
    int numFriendRequests(vector<int>& ages) 
    {
        int totRequest = 0 ;
        unordered_map<int,int> mp ;
        
        
        for (int it : ages )
            mp[it]++ ;
        
        
        for ( auto it : mp )
        {
            for ( auto i : mp )
            {
                int p1 = it.first ;
                int p2 = i.first ;
                if( !( p2 <= 0.5*p1+7 || p2 > p1 || p2 > 100 && p1 < 100 ))
                {
                    int num ;
                    if ( it.first == i.first )
                        num =  1 ;
                    else num = 0 ; 
                    totRequest += it.second * (i.second - num ) ;
                }
            }
        }
        return totRequest ;
    }
};
