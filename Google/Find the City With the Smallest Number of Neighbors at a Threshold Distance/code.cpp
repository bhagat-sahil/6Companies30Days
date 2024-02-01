class Solution {
public:
    
    int bfs( vector<vector<pair<int, int>>> &adj, int source, int threshold,  int n) 
    {
        queue<pair<int, int>> queue ;
        vector<bool> vis(n, false) ;
        queue.push({source, 0}) ;
        
        
        int count = 0 ;
        
        while( !queue.empty() ) 
        {
            
            int curr = queue.front().first ;
            int dist = queue.front().second ;
            vis[curr] = true ;
            queue.pop() ;
            
            
            if ( dist > threshold ) continue ;
            
            for( auto &it : adj[curr] ) 
            {
                int adjNode = it.first ;
                int wt = it.second ;
                
                if( !vis[adjNode] && wt + dist <= threshold )
                {
                    queue.push( { adjNode, wt + dist } ) ;
                    count++ ;                
                }
            }
        }
        return count;
    }
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<pair<int,int>>> adj(n) ;
        
        for( auto &it : edges) 
        {
            adj[it[0]].push_back( {it[1], it[2]} ) ;
            adj[it[1]].push_back( {it[0], it[2]} ) ;
        }
        
		int ans = n - 1 ;
        int count = n - 1 ;
        for( int i = 0 ; i < n ; i++ ) 
        {
            int val = bfs( adj, i, distanceThreshold, n ) ;  
            if( count >= val ) 
            {
                count = val ;
                ans = i ;
            }
        }
        return ans ;
        
    }
};
