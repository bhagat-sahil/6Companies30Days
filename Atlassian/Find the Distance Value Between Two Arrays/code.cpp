class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int count = 0 ;
        int n = size(arr1) ;
        int m = size(arr2) ;
        for ( int i = 0 ; i < n ; i++ )
        {
            bool check = true ;
            for ( int j = 0 ; j < m ; j++ )
            {
                if ( abs((arr1[i] - arr2[j])) <= d )
                    check = false ;
            }
            if ( check )    count++ ;
            
        }
        return count ;
    }
};
