class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& size ) 
    {
        int m = greed.size() ;
        int n = size.size() ;
        
        sort(begin(greed), end(greed)) ;
        sort(begin(size), end(size)) ;
        
        
        int i = 0 ;
        int j = 0 ;
        
        while( i < m && j < n ) 
        {
            if( greed[i] <= size[j] ) 
                i++;
            j++;
        }
        
        return i;
    }
};
