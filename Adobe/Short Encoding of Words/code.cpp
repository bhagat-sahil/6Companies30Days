class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        unordered_set<string> st(begin(words), end(words)) ;
        
        for( auto it : st )
        {
            for ( int i = 1 ; i < size(it) ; i++ )
            {
                st.erase(it.substr(i)) ;
            }
        }
        
        int ans = 0 ;
        for ( auto it : st )
            ans = ans + size(it) + 1 ;
        
        return ans ;
    }
};
