class Solution {
public:
    
    
    int check ( vector<int>& p1,  vector<int>& p2,  vector<int>& p3) 
    {
        int x1 = p1[0] ; 
        int x2 = p2[0] ; 
        int x3 = p3[0] ; 
        
        int y1 = p1[1] ;
        int y2 = p2[1] ;
        int y3 = p3[1] ;
        
        return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2) ;
     
    }
    
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
        sort( begin(trees), end(trees)) ;
        
        
        vector<vector<int>>upper, lower ;
        
        for ( auto &coordinate : trees )
        {
            while ( size(lower) >= 2 && 
                check(lower[lower.size() - 2], lower[lower.size() - 1], coordinate ) > 0 )
                lower.pop_back() ;
            
            while ( size(upper) >= 2 && 
                check(upper[upper.size() - 2], upper[upper.size() - 1], coordinate ) < 0 )
                upper.pop_back() ;
                
            
            lower.push_back(coordinate) ;
            upper.push_back(coordinate) ;
        }
        
        set<vector<int>>st ;
        
        for ( auto &it : lower ) 
            st.insert(it) ;
        for ( auto &it : upper ) 
            st.insert(it) ;
        
        
        vector<vector<int>>ans ;
        
        for ( auto &it : st )
            ans.push_back(it) ;
        
        return ans ;
    }
};
