class Solution {
public:
    
    string ones [20] = {"", " One", " Two", " Three", " Four", " Five",
                      " Six", " Seven", " Eight", " Nine", " Ten",
                      " Eleven", " Twelve", " Thirteen", " Fourteen",
                      " Fifteen", " Sixteen", " Seventeen", " Eighteen",
                      " Nineteen"} ;
    
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty",
                       " Sixty", " Seventy", " Eighty", " Ninety"} ;
    
    string thousands [4] = {"", " Thousand", " Million", " Billion"} ;
    
    
    string findString ( int num )
    {
        if ( num < 20 ) return ones[num] ;
        
        if ( num < 100 )    return tens[num/10] + findString( num % 10 ) ;
        
        if ( num < 1000 )   return findString(num/100) + " Hundred" + findString( num % 100 ) ;
        
        for ( int i = 3 ; i >= 0 ; i-- )
        {
            if ( num>=pow(1000,i))
            {
               return findString(num/pow(1000, i)) + thousands[i] + findString(num%(int)pow(1000, i));
            }
        }
        return "" ;
    }
    
    
    
    
    
    string numberToWords(int num) {
        if ( num == 0 ) return "Zero" ;
        if ( num < 20 ) return ones[num].substr(1) ;
        
        return findString( num ).substr(1) ;
        
    }
};
