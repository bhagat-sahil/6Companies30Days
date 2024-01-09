class Solution {
public:
    
    vector<long long> solve(int a, vector<pair<int,int>>adj[]) 
    {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,a}) ;
        vector<long long>dist(26,-1) ;
        while( !q.empty()) 
        {
            pair<long long,int>p=q.top() ;
            q.pop() ;
            for( auto i : adj[p.second] ) 
            {
                if( dist[i.first] == -1 || p.first+i.second<dist[i.first] ) 
                {
                    dist[i.first] = p.first+i.second ;
                    q.push({dist[i.first],i.first}) ;
                }
            }
        }
        return dist ;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<pair<int,int>>adj[26] ;
        int n=changed.size() ;
        map<int,vector<long long>>map ;
        
        for(int i = 0 ; i < n ; i++ ) 
        {
            adj[original[i]- 'a'].push_back({changed[i]-'a', cost[i]}) ;
        }
        
        
        for(int i = 0 ; i < 26 ; i++ ) 
        {
            vector<long long>temp = solve(i,adj) ;
            map[i] = (temp) ;
        }
        n = source.size();
        long long ans = 0 ;
        
        for( int i = 0 ; i < n ; i++ ) 
        {
            if( source[i] != target[i] ) 
            {
                long long temp=map[source[i]-'a'][target[i]-'a'] ;
                if( temp == -1 )
                    return -1 ;
                ans = ans + temp ;
            }
        }
        return ans ;
    }
};
