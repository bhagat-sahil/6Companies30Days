class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX)) ;
        
        for(auto current : edges)
        {
            int to = current[0] ;
            int from = current[1] ;
            int weight = current[2] ;
            
            distance[to][from] = weight ;
            distance[from][to] = weight ; 
        }
        
        for( int m = 0 ; m < n ; m++ )
        {
            for(int source = 0 ; source < n ; source++ )
            {
                for(int destination = 0 ; destination < n ; destination++ )
                {
                    if( source == destination )
                    {
                        distance[source][destination] = 0 ;
                        continue;
                    }
                    if( distance[source][m] != INT_MAX && distance[m][destination] != INT_MAX )
                    {
                        distance[source][destination] = min(distance[source][destination],
                                                         distance[source][m]+distance[m][destination]);
                    }
                }
            }
        }
        
        vector<int>cityCount(n,0);
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( distance[i][j] <= distanceThreshold )
                    cityCount[i]++ ;
            }
        }
        
        int ans = 0;
        int minCount = INT_MAX;
        for( int i = 0 ; i < n ; i++ )
        {
            if( cityCount[i] <= minCount )
            {
                minCount = cityCount[i] ;
                ans = i ;
            }
        }
        return ans ;
    }
};
