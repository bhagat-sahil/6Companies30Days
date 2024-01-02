class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int repeated = -1 ;
        unordered_map<int,int>m ;
        for ( auto it : arr )
        {
            m[it]++ ;
            if ( m[it] == 2 ) repeated = it ;
        }
        
        int missing = -1 ;
        for ( int i = 0 ; i <= n ; i++ )
        {
            if( m[i] == 0 ) missing = i ;
        }
        vector<int>ans(2) ;
        ans[0] = repeated ;
        ans[1] = missing  ;
        return ans ;
    }
};
