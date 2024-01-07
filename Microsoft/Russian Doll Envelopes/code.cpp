bool compare(const vector<int>& a, const vector<int>& b) 
    {
        if (a[0] == b[0]) 
        {
            return a[1] > b[1];
        } else 
        {
            return a[0] < b[0];
        }
    }
class Solution {
public:
    
//     int countRussianDolls( int curr, int i,  vector<vector<int>>& envelopes, vector<vector<int>>&dp )
//     {
//         if ( i < 0 )   return 1 ;
//         int left = 0 ;
        
        
//         if ( dp[curr][i] != -1 )    return dp[curr][i] ;
        
        
//         if ( envelopes[curr][0] > envelopes[i][0]
//            && envelopes[curr][1] > envelopes[i][1] && i != curr )
//         {
//             left = 1 + countRussianDolls( i, i-1, envelopes, dp ) ;
//         }
//         int right = countRussianDolls( curr, i-1, envelopes, dp ) ;
        
//         return dp[curr][i] = max( left, right ) ;
//     }
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), compare) ; 
        vector<int> dp;
        for (const auto& env : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), env[1]);
            if (it == dp.end()) {
                dp.push_back(env[1]);
            } else {
                *it = env[1];
            }
        }
        return dp.size();
    }
};
