class Solution {
public:
    
    
    void findCombinations( int n, string &temp, vector<string>&ans, string &digits, unordered_map<char, string >&m )
    {
        if ( n == digits.size())
        {
            ans.push_back(temp) ;
            return ;
        }
        string str = m[digits[n]] ;
        for ( int i = 0 ; i < str.size() ; i++ )
        {
            temp.push_back(str[i]) ;
            findCombinations( n+1, temp, ans, digits, m ) ;
            temp.pop_back() ;
        }
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string>ans ;
        if ( digits.size() == 0  ) return ans ;
        string temp ;
        unordered_map<char, string > m ;
        m['2'] = "abc" ;
        m['3'] = "def" ;
        m['4'] = "ghi" ;
        m['5'] = "jkl" ;
        m['6'] = "mno" ;
        m['7'] = "pqrs" ;
        m['8'] = "tuv" ;
        m['9'] = "wxyz" ;
        findCombinations( 0, temp, ans, digits, m ) ;
        return ans ;
    }
};
