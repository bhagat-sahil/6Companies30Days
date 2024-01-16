class Solution {
public:
    
    
    string add( int f, auto ch )
    {
        string temp = "" ;
        for ( int i = 0 ; i < f ; i++ )
        {
            temp+= ch ;
        }
        return temp ;
    }
    
    string frequencySort(string s) 
    {
        unordered_map<char, int> m ;
        
        for ( auto ch : s )
        {
            m[ch]++ ;
        }
        
        priority_queue<pair<int, char>>pq ;
        
        string ans = "" ;
        
        
        for ( auto it : m )
        {
            pq.push({it.second,it.first}) ;
        }
        
        while ( !pq.empty())
        {
            auto TOP = pq.top() ;
            int frequency = TOP.first ;
            char ch = TOP.second ;
            pq.pop() ;
            ans = ans + add( frequency, ch ) ;
        }
        return ans ;
        
    }
};
