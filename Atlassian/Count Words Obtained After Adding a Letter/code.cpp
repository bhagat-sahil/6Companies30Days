class Solution {
public:
    
    
    int wordCount(vector<string>& sw, vector<string>& tw) 
    {
        
        unordered_set<string>s ;
        int count = 0 ;
        for ( int i = 0 ; i < size(sw) ; i++ )
        {
            string temp = sw[i] ;
            sort( begin(temp), end(temp) ) ;
            s.insert(temp) ;
        }
        
        for ( int i = 0 ; i < size(tw) ; i++ )
        {
            string temp = tw[i] ;
            sort( begin(temp), end(temp) ) ; 
            bool check = false ;
            for ( int j = 0 ; j < size(temp) ; j++ )
            {
                string str = temp.substr(0,j) + temp.substr(j+1) ;
                if( s.find(str) != s.end())
                {
                    check = true ;
                    break ;
                }
            }
            if ( check )    count++ ;
        }
        return count ;
    }
};
