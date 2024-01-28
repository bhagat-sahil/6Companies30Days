class Solution {
public:
    
    
    void dfs ( int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited )
    {
        int m = grid.size() ;
        int n = grid[0].size() ;
        visited[x][y] = 1 ;
        
        int dr[] = { 1,-1, 0, 0 } ;
        int dc[] = { 0, 0,-1, 1 } ;
        for ( int i = 0 ; i < 4 ; i++ )
        {
            int r = dr[i] + x ;
            int c = dc[i] + y ;
            
            if ( r<m && r>=0 && c<n && c>=0 && grid[r][c] && visited[r][c] == -1 )
            {
                dfs( r, c, grid, visited ) ;
            }
        }
    }
    
    
    
    
    int islandCount( vector<vector<int>>& grid )
    {
        int count = 0 ;
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<int>>visited(m,vector<int>(n,-1)) ;
        
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( grid[i][j] && visited[i][j] == -1 )
                {
                    dfs( i, j, grid, visited)  ;
                        count++ ;
                }
            }
                     
        }
        return count ;
    }
    
    
    
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        int CountIsland = islandCount( grid ) ;
        
        if ( CountIsland > 1 || CountIsland == 0 )  return 0 ;
        
        else
        {
            for ( int i = 0 ; i < m ; i++ )
            {
                for ( int j = 0 ; j < n ; j++ )
                {
                    if ( grid[i][j] )
                    {
                        grid[i][j] = 0 ;
                        int Icount = islandCount(grid) ; 
                        
                        if ( Icount  > 1 || Icount  == 0 ) return 1 ;
                        
                        grid[i][j] = 1 ;
                    }
                }
                     
            }
            
        }
        return 2 ;
    }
};
