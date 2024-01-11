class Solution {
public:
    
    void dfs( int r, int c, vector<vector<int>>&visited, vector<vector<char>>& board )
    {
        
        int m = board.size() ;
        int n = board[0].size() ;
        visited[r][c] = 1 ;
        
        int dr[] = { 0, 1 } ;
        int dc[] = { 1, 0 } ;
        
        
        for ( int i = 0 ; i < 2 ; i++ )
        {
            int nr = dr[i] + r ;
            int nc = dc[i] + c ;
            
            if ( nr < m && nc < n && visited[nr][nc] == -1 && board[nr][nc] == 'X' )
            {
                dfs( nr, nc, visited, board ) ;
                cout<<nr<<" : "<<nc<<", vist: "<<visited[nr][nc]<<endl;
            }
            
        }
    }
    
    int countBattleships(vector<vector<char>>& board) 
    {
        int m = board.size() ;
        int n = board[0].size() ;
        vector<vector<int>>visited(m,vector<int>(n,-1)) ;
        int count = 0 ;
        
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( board[i][j] == 'X' && visited[i][j] == -1 )
                {
                    // cout<<i<<" : "<<j<<", vist: "<<visited[i][j]<<endl;
                    dfs( i, j, visited, board ) ;
                    count++ ;
                }
            }
        }
        return count ;
    }
};
