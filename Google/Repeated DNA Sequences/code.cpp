class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> ans ;
        
        if ( size(s) < 11 ) return ans ;
        unordered_map<string,int> count ;
        
        for ( int i = 0 ; i < size(s)-9 ; i++ )
        {
            string temp = s.substr( i, 10 ) ;
            count[temp]++ ;
        }
        
        
        for ( auto &it : count )
        {
            if ( it.second >= 2 )   
                ans.push_back(it.first) ;
        }
        return ans ;
    }
};
