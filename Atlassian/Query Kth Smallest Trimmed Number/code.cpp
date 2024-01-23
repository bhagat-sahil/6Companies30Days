class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q ) 
    {
        vector<int>ans ;
        for ( auto it : q )
        {
            int nthSmallest = it[0] ;
            int trimDigitCount = it[1] ;
            vector<pair<string,int>>d ;
            for ( int i = 0 ; i < size(nums) ; i++ )
            {
                string num = nums[i] ;
                d.push_back({num.substr(size(num)-trimDigitCount), i}) ;
            }
            sort(begin(d), end(d)) ;
            ans.push_back(d[nthSmallest-1].second) ;
        }
        return ans ;
    }
};
