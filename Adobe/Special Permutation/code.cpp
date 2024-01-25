class Solution {
public:
    
    int mod = 1e9 + 7;
    int help(vector<int> &nums, int prev, int visited, vector<vector<int>>& dp) 
    {
        int ans = 0;
        int n = nums.size() - 1;

        if (visited == ((1 << n) - 1)) return 1;

        if (dp[prev][visited] != -1) return dp[prev][visited];


        for (int i = 0; i < n; i++) 
        {
            if ( (nums[prev] % nums[i] == 0 ||
                  nums[i] % nums[prev] == 0) &&
                !(visited & (1 << i)) ) 
            {
                ans += help(nums, i, visited | (1 << i), dp);
                ans %= mod ;
            }
        }

        return dp[prev][visited] = ans;
    }
    
    
    int specialPerm(vector<int>& nums) 
    {
        int n = nums.size();
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int> (1 << n, -1));
        return help(nums, n, 0, dp);
    }
};
