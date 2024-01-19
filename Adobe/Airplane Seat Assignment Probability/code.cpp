class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans = 1 ;
        if ( n <= 2 )   
        return ans/n ;
        else return ans/2 ;
    }
};
