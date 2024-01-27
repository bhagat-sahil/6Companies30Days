class Solution {
public:
    int stoneGameVI(vector<int>& aV, vector<int>& bV ) 
    {
         priority_queue<pair<int,pair<int,int>>>pq ;
        
        for ( int i = 0 ; i < size(aV) ; i++ )
            pq.push( { aV[i] + bV[i], {aV[i], bV[i]} } ) ;
        
        int aSum = 0 ;
        int bobSum = 0 ;
        
        bool turn = true ;
        
        while ( !pq.empty())
        {
            auto top = pq.top() ;
            pq.pop() ;
            if ( turn )
            {
                aSum += top.second.first ;
                turn = false ;
            }
            else
            {
                bobSum += top.second.second ;
                turn = true ;
            }
        }
        
        if ( aSum == bobSum )   return 0 ;
        
        else if ( aSum > bobSum )    return 1 ;
        
        else return -1 ;
    }
};
