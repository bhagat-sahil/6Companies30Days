class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        int n = nums.size() ;
        map<vector<int>,int> m ;
        for ( int i = 0 ; i < n ; i++ )
        {
            vector<int>temp ;
            int count = 0 ;
            for ( int j = i ; j < n ; j++ )
            {
                if ( nums[j] %p == 0 ) count++ ;
                if ( count > k ) break ;
                temp.push_back(nums[j]) ;
                m[temp]++ ;
            }
        }
        int ans = m.size() ;
        return ans ;
    }
};
