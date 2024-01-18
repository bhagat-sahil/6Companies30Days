// Approach 1


class Solution {
public:
    
    int maxSum( int i, int j, vector<int>&nums, int k, unordered_map<string, int> &mp )
    {   
        if ( i == size(nums))   return 0 ;
        
        string s = to_string(j) + "+" + to_string(i);
        
        if(mp.find(s) != end(mp))
            return mp[s];
        
        int ans = 0 ;
        
        
        if ( i - j <= k || j == -1 ) 
        {
            int pick = nums[i] + maxSum( i+1, i, nums, k, mp ) ;
            int notPick = maxSum( i+1, j, nums, k, mp ) ;
            
            ans = max( pick, notPick ) ;
        }
        return mp[s] = ans ;
    }
    
    
    
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        unordered_map<string, int> mp;
        int ans =  maxSum( 0, -1, nums, k, mp ) ;
        
        if ( ans == 0 )
            return *max_element( nums.begin(), nums.end()) ;
        else return ans ;
    }
};
