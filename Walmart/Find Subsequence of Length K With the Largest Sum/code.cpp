class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        vector<int>ans ;
        int n = size(nums) ;
        
        
        for ( int i = 0 ; i < k ; i++ )
            ans.push_back(nums[i]) ;
        
        for ( int i = k ; i < n ; i++ )
        { 
            // FINDING THE INDEX OF MIN ELEMENT IN ANS TC- O(N)
            int IdxMinEle = min_element(ans.begin(), ans.end()) - ans.begin() ;
            
            if ( ans[IdxMinEle] < nums[i])
            {
                ans.erase( ans.begin() + IdxMinEle ) ;
                ans.push_back(nums[i]) ;
            }   
        }
        return ans ;
    }
};
