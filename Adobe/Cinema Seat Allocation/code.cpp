class Solution {
public:
    bool check(int s, int e, vector<int>&reservedSeats)
    {
        for (int it : reservedSeats)
        {
            if ( it >= s && it <= e )
            {
                return false ;
            }
        }
        return true ;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, vector<int>> mp ;

        for (auto it : reservedSeats)
        {
            if (it[1] == 1 or it[1] == 10)
                continue;
            
            mp[it[0]].push_back(it[1]) ;
        }

        int ans = ( n - size(mp) ) * 2 ;

        for (auto it : mp )
        {
            if ( check(2, 5, it.second) || 
                 check(4, 7, it.second) ||
                check(6, 9, it.second) )
                ans++ ;
        
        }
        return ans ;
    }
};
