class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            nums[i] = nums[i] % 2 ;
        }
        unordered_map<int,int>map ;
        map [0] = 1 ;
        int preSum = 0 ; 
        int count = 0 ;
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            preSum = preSum + nums[i] ;
            int remove = preSum - k ;
            count = count + map[remove] ;
            map[preSum] = map[preSum] + 1 ;
        }
        return count ;
    }
};
