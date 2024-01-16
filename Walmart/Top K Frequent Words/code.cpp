class Solution {
public:
    
    
    
    class comp {
        public:
        
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> m ;
        for(string& word : words) 
        {
            m[word]++ ;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for( auto it : m ) 
        {
            if ( pq.size() < k ) 
                pq.push({it.second,it.first}) ;
            
            
            else 
            {
                if ( pq.top().first < it.second )
                {
                    pq.pop() ;
                    pq.push({it.second,it.first}) ;
                }
                
                else if ( pq.top().first == it.second && pq.top().second > it.first )
                {
                    pq.pop() ;
                    pq.push({it.second,it.first}) ;
                }    
            }
        }
        vector<string> ans ;
        while(!pq.empty()) {
            ans.push_back(pq.top().second) ;
            pq.pop() ;
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }

    
};
