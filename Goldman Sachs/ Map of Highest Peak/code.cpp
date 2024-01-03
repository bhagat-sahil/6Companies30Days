class Solution {
public:
    
    void calculateHeights( queue<pair<int,int>>&q, vector<vector<bool>>&visited ,
                          vector<vector<int>>&ans, vector<vector<int>>&isWater )
    {
        int m = isWater.size() ;
        int n = isWater[0].size() ;
        int drow[] = { 0, 1, -1, 0 } ;
        int dcol[] = { 1, 0, 0, -1 } ;
        while( !q.empty())
        {
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            
            for ( int i = 0 ; i < 4 ; i++ )
            {
                int r = drow[i] + row ;
                int c = dcol[i] + col ;
                
                if ( r>=0 && r<m && c>=0 && c<n && visited[r][c] == false )
                {
                    q.push({r,c}) ;
                    ans[r][c] = ans[row][col] + 1 ;
                    visited[r][c] = true ;
                }
            }
        }
    }
    
    
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = isWater.size() ;
        int n = isWater[0].size() ;
        vector<vector<bool>>visited(m,vector<bool>(n,false)) ;
        vector<vector<int>>ans(m,vector<int>(n,0)) ;
        queue<pair<int,int>>queue ;
        
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( isWater[i][j] == 1 )
                {
                    queue.push({i,j}) ;
                    visited[i][j] = true ;
                }
            }
        }
        calculateHeights( queue, visited, ans, isWater ) ;
        return ans ;
    }
};
