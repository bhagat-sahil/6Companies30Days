

/*You are required to complete this function */

string encode(string src)
{
    int i = 0 ; 
    int j = 1 ;
    int count = 1 ;
    string ans = "" ;
    while ( j < src.size()+1 )
    {
        
        if ( src[i] == src[j] ) count++ ;
        else 
        {
            ans = ans + src[i] + to_string(count) ;
            count = 1 ;
        }
        i++ ;
        j++ ;
    }
    
    return ans ;
}     
 
