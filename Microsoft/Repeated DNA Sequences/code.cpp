class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string>ans ;
        if ( s.size() < 10 )   return ans ;
        
        unordered_map<string,int>sequenceCount ;
        
        for ( int i = 0 ; i <= s.size()- 10 ; i++ )
        {
            string temp = s.substr( i, 10 ) ;
            sequenceCount[temp]++ ;
        }
        for ( auto it : sequenceCount )
        {
            if ( it.second > 1 ) ans.push_back(it.first) ;
        }
        return ans ;
    }
};
