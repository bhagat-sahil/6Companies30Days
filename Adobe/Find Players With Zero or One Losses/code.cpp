class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
   
        unordered_map<int,int> mp ;
        vector<int>loser ;
        vector<int>winner ;
        
        for ( auto it : matches )
        {
            mp[it[1]]++ ;
        }
        
        
        for ( auto it : matches )
        {
            int l = it[1] ;
            int w = it[0] ;
            
            if ( mp.find(w) == mp.end() )
            {
                winner.push_back(w) ;
                mp[w] = 4 ;
            }
            if ( mp[l] == 1 ) loser.push_back(l) ;
                
        }
        sort(begin(loser),end(loser)) ;
        sort(begin(winner),end(winner)) ;
        
        return { winner, loser } ;
    }
};
