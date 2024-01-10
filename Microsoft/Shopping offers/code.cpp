class Solution {
public:
    
    int findCost( vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string,int>&dp )
    {
        string key = "";
        for (int i = 0; i < needs.size(); i++) {
            key += to_string(needs[i]) + ",";
        }

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        
        
        int cost = 0 ;
        for ( int i = 0 ; i < price.size() ; i++ )
        {
            cost = cost + price[i] * needs[i] ;
        }
        cout<<cost<<" ";
        
        int costAfterDiscount = INT_MAX ;
        vector<int>temp ;
        for ( auto it : special )
        {
            bool flag = true ;
            for ( int i = 0 ; i < price.size() ; i++ )
            {
                if ( needs[i] < it[i] )
                    flag = false ;
            }
            
            vector<int>new_needs ;
            if ( flag )
            {
                new_needs = needs ;
                for ( int i = 0 ; i < needs.size() ; i++ )
                {
                    new_needs[i] = needs[i] - it[i] ;
                    temp = new_needs ;
                }
                    
                costAfterDiscount = min(costAfterDiscount,it[it.size()-1] + findCost( price, special, new_needs, dp )) ;
            }
        }
        
        int result = min(cost, costAfterDiscount);
        dp[key] = result;
        return result;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        unordered_map<string,int>dp ;
        return findCost( price, special, needs, dp ) ;
    }
};
