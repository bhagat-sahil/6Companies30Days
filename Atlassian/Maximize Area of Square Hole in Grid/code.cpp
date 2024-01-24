class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        sort( begin(hBars), end(hBars) ) ;
        sort( begin(vBars), end(vBars) ) ;
        
       
        int cntHBars = 1 ;
        int currCntHBars = 1 ;
        
        for ( int i = 0 ; i < size(hBars)-1 ; i++ )
        {
            if( hBars[i] + 1 == hBars[i+1] )      
                currCntHBars++ ;
            else 
                currCntHBars = 1 ;
            cntHBars = max(cntHBars, currCntHBars) ;
        }

        
        int cntVBars = 1 ;
        int currCntVBars = 1 ;
        
        for ( int i = 0 ; i < vBars.size()-1 ; i++ )
        {
            if( vBars[i] + 1 == vBars[i+1] )      
                currCntVBars++ ;
            else 
                currCntVBars = 1 ;
            cntVBars = max(cntVBars, currCntVBars) ;
        }

        int ans = min(cntHBars, cntVBars) + 1 ;
        return ans * ans ;
    }
};
