class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0 ;
        int val = 0 ;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
			sum = sum + nums[i] ;
			val = val + i*nums[i] ;
		}
        
        int totSum = val ;
        
        for(int i = nums.size()-1 ; i > 0 ; i-- )
        {
            val = val + sum - nums.size()*nums[i] ;
            totSum = max( val, totSum ) ;
        }
        return totSum;
    }
    
};
