class Solution {
public:
    
    bool checkSubsequence(string s1, string s2) 
    {
        int i = 0, j = 0;
        
        while ( i < size(s1) && j < size(s2)) 
        {
            
            if (s1[i] == s2[j])
                i++; 
            
            j++;
        }
        
        return i == size(s1);
    }
    
    string findLongestWord(string s, vector<string>& d) 
    {
        string ans = "";
        
        for ( auto str : d ) 
        {
            
            if (checkSubsequence(str, s)) 
            {
                
                if (str.size() > ans.size() || (str.size() == ans.size() && str < ans))
                    ans = str;
            }
        }
        
        return ans ;
    }
};
