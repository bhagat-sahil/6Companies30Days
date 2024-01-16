class Solution {
public:

    int findPairs( vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end()) ;
        int n = size(nums) ;

        int left = 0 ;
        int right = 1 ;
        int ans = 0 ;
        
        while ( right < n ) 
        {
            int diff = abs(nums[right] - nums[left]) ;
            if ( diff == k ) 
            {
                ans++ ;
                while ( ++right < n && nums[right] == nums[right - 1] ) ;
            } 
            else if (diff < k) 
            {
                right++;
            } 
            else 
            {
                while ( ++left < n && nums[left] == nums[left - 1] ) ;
                right = left + 1 ;
            }
        }
        return ans ;
    }

};
