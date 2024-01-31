class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans ;
        for ( auto &it : queries ) 
        {
            int trim = it[1] ;
            int nthSmallest = it[0] ;
            
            vector<pair<string,int>>temp ;
            for ( int i = 0 ; i < size(nums) ; i++ )
            {
                int n = size(nums[i]) ;
                
                temp.push_back({nums[i].substr(n-trim),i}) ;
                
            }
            sort(begin(temp),end(temp)) ;
            ans.push_back(temp[nthSmallest-1].second) ;
        }
        
        return ans ;
    }
};
