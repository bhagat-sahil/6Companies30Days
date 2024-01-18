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

//Bottom Up
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size() ;
        
        vector<int> dp(n, 0) ;
        
        for(int i = 0 ; i < n ; i++ )
            dp[i] = nums[i] ;
        
        int res = dp[0] ;
        
        for(int i = 1 ; i < n ; i++ ) 
        {
            for( int j = i-1 ; i-j <= k && j >= 0 ; j-- ) 
            {
                dp[i] = max( dp[i], nums[i] + dp[j] ) ;
            }
            res = max( res, dp[i] ) ;
        }
        return res ;
    }
};


//Approach-4 - Priority_queue

 // REDUCING THE TC BY USING PRIORITY QUEUE INSTEAD OF INNER LOOP 

class Solution {
public:
    

    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size() ;
        
        
        vector<int> dp(n, 0) ;
        dp = nums ;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq ;
        
        pq.push( {dp[0], 0} ) ;
        
        int res = dp[0] ;
        
        for( int i = 1 ; i < n ; i++ )
        {
            
            while( !pq.empty() && pq.top().second < i - k ) 
                pq.pop();
                
            
            dp[i] = max( dp[i], nums[i] + pq.top().first ) ;
            
            pq.push( {dp[i], i} ) ;
            
            res = max( res, dp[i] ) ;
        }
        return res ;
    }
};



















