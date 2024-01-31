
class Solution {
public:


    
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        vector<vector<int>>roadCanTake ;
        map<vector<int>, int> distance ;
        distance[start] = 0 ;
        for ( auto &it : sr )
        {
            int a = it[0], b = it[1], c = it[2], d = it[3], cost = it[4];
            if(cost < abs(a-c) + abs(b-d)){
                roadCanTake.push_back({a,b,c,d,cost});
                distance[{c,d}] = abs(start[0] - c) + abs(start[1] - d);
            } 
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        
        pq.push({0, start[0], start[1]}) ;

        while( !pq.empty())
        {
            auto top = pq.top() ;
            pq.pop() ;
            
            int x = top[1] ;
            int y = top[2] ;
            
            int minDistance = top[0] ;
            

            
            for( auto &it : roadCanTake )
            {
                int a = it[0] ;
                int b = it[1] ;
                int c = it[2] ;
                int d = it[3] ;
                int cost = it[4] ; 

                if( distance[{c,d}] > minDistance 
                   + abs( x - a ) 
                   + abs( y - b ) 
                   + cost )
                {
                    distance[{c,d}] = minDistance + abs( x - a ) + abs( y - b ) + cost ;
                    pq.push({distance[{c,d}], c, d}) ;
                }
            }
        }

        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        
        for(auto &it : roadCanTake )
        {
            int x = target[0], y = target[1];
            int a = it[0] ;
            int b = it[1] ;
            int c = it[2] ;
            int d = it[3] ;
            int cost = it[4] ;
            ans = min( ans, distance[{c,d}] + abs( c - x ) + abs( d - y )) ;
          
        }
        return ans ;
    }
        
};
