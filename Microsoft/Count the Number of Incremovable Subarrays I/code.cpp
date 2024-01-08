class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) 
    {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++ )
        {
            for(int j = i; j < nums.size(); j++ )
            {
                int prev = 0 ;
                int check = 1;
                for(int k = 0; k < nums.size(); k++ )
                {
                    if(k >= i && k <= j) continue ;
                    if(prev >= nums[k])
                    { 
                        check = 0 ; 
                        break ; 
                    }
                    prev = nums[k] ;
                }
                if(check) ans++ ;
            }
        }
        return ans;
    }
};
