class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a ) 
    {
        long long m = mass ;
        sort(begin(a), end(a)) ;
        for ( auto it : a )
        {
            if ( it > m )    return false ;
            m += it ;
        }
        return true ;
    }
};
