class Solution {
public:
    int longestString(int x, int y, int z) 
    {
        if ( x == y ) return 2*x+2*y+2*z ;
        int temp = min( x, y ) ;
        int ans = (temp+1)*2 +2*temp + z*2 ;
        return ans ;
    }
};
