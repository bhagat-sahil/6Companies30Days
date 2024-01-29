
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
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size() ;
        sort(begin(envelopes), end(envelopes), compare ) ;
        
        vector<int> dp ;
        
        dp.push_back(envelopes[0][1]) ;
        for ( int i = 1 ; i < n ; i++)
        {
            if( dp.back() < envelopes[i][1] )
                dp.push_back(envelopes[i][1]) ;
            
            else
            {
                auto it = lower_bound( begin(dp), end(dp),
                                    envelopes[i][1])-begin(dp) ;
                dp[it] = envelopes[i][1] ;
            }
        }
        return dp.size();
    }
};
