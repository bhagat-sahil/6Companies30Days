class Solution {
public:
    
    void bfs( int i, int j, vector<vector<int>> &ans, vector<vector<int>>& vis )
    {
        int n = vis.size() ;
        int m = vis[0].size() ;
        
        queue<pair<int,int>> q ;
        q.push({i, j}) ;
        vis[i][j] = 1 ;
        vector<int> temp(2) ;
        temp[0] = i ;
        temp[1] = j ;
        ans.push_back(temp);
        
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int cur_i = cur.first;
            int cur_j = cur.second;
            
            for (int d=0 ; d<4 ; d++)
            {
                int ni = cur_i + dr[d];
                int nj = cur_j + dc[d];
                if ( ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj])
                {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                    temp[0]=ni;
                    temp[1]=nj;
                    ans.push_back(temp);
                }
            }
        }
    }
    
    vector<vector<int>> allCellsDistOrder(int r, int c, int x, int y) 
    {
        vector<vector<int>> ans;
        vector<vector<int>> vis(r,vector<int>(c,0));
        bfs(x, y, ans, vis );
        return ans;
    }
};
