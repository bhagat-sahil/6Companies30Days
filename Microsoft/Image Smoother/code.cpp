class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m = img.size() ;
        int n = img[0].size() ;
        vector<vector<int>>ansImage(m,vector<int>(n,0)) ;
        
        int drow[] = { 0, 0, 1, 1, 1, -1, -1, -1 } ;
        int dcol[] = { -1, 1, -1, 0, 1, 0, -1, 1 } ;
        
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                int avg = img[i][j] ;
                int count = 1 ;
                for ( int a = 0 ; a < 8 ; a++ )
                {
                    int r = drow[a] + i ;
                    int c = dcol[a] + j ;
                    if ( r>=0 && r<m && c>=0 && c<n  )
                    {
                        avg = avg + img[r][c] ;
                        count++ ;
                    }
                }
                ansImage[i][j] = avg/count ;
            }
        }
        return ansImage ;
    }
};
