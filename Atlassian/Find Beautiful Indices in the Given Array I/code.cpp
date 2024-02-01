class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) 
    {
        int n = size(s) ;
        int s1 = size(a) ; 
        int s2 = size(b) ;
        int i = 0, j = 0;
        vector<int> ans, temp, temp1 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == a[0])
            {
                string subS = s.substr( i, s1 ) ;
                if ( subS == a )
                    temp.push_back(i) ;
            }
            if(s[i] == b[0])
            {
                string subS = s.substr( i, s2 ) ;
                if(subS == b)
                    temp1.push_back(i) ;
            }
        }
        s1 = size(temp), s2 = size(temp1);
        while(i < s1 && j < s2)
        {
            int val = abs( temp[i] - temp1[j] ) ;
            if ( val <= k )
                ans.push_back( temp[i++]) ;
            
            else if( temp[i] < temp1[j] )
                i++ ;
            
            else
                j++ ;
        }
        return ans;
    }
};
